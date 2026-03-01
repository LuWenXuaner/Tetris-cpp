#include "CBoard.h"
#include <QLabel>
#include <QPainter>
#include <QKeyEvent>
#include <QRandomGenerator>

CBoard::CBoard(QWidget *parent):QFrame(parent)
{
    //随机生成方块
    nextPiece.setRandomShape();
    clearBoard();
    setFocusPolicy(Qt::StrongFocus);

    //设置音乐和音效
    bgMusic.setAudioOutput(&audioOutput);
    audioOutput.setVolume(0.4);
    bgMusic.setSource(QUrl("qrc:/sounds/NWAFU.mp3"));
    bgMusic.setLoops(QMediaPlayer::Infinite);

    removeSound.setSource(QUrl("qrc:/sounds/remove.wav"));//移动声音
    downSound.setSource(QUrl("qrc:/sounds/down.wav"));//下降声音
    gameOverSound.setSource(QUrl("qrc:/sounds/gameover.wav"));//游戏结束音乐
}

//记录方块信息
void CBoard::setNextPieceLabel(QLabel *label)
{
    nextPieceLabel = label;
}

void CBoard::setContent(QLabel *content)
{
    con = content;
    con -> setText("");
}

//创建信息对应的图片
void CBoard::showNextPiece()
{
    if(!nextPieceLabel)
        return;//指针为空进行返回

    //确定图片大小（求具体宽度）（单位：块）
    int dx = nextPiece.maxX() - nextPiece.minX() + 1;
    int dy = nextPiece.maxY() - nextPiece.minY() + 1;

    //绘图（单位：像素）
    QPixmap pixmap(dx * squareWidth(), dy * squareHeight());//块数乘以每块像素数
    QPainter painter(&pixmap);
    painter.fillRect(pixmap.rect(), QColor(3, 54, 73));

    //绘制四个小块
    //以左上角为（0,0）点
    for(int i = 0;i < 4;++i)
    {
        int x = nextPiece.x(i) - nextPiece.minX();
        int y = nextPiece.y(i) - nextPiece.minY();
        drawSquare(painter, x * squareWidth(), y * squareHeight(), nextPiece.shape());
    }

    nextPieceLabel->setPixmap(pixmap);
}

//处理新块
void CBoard::newPiece()
{
    curPiece = nextPiece;
    nextPiece.setRandomShape();
    showNextPiece();
    curX = BoardWidth / 2;
    curY = BoardHeight - 1 + curPiece.minY();

    //把当前块摆放到起始位置（中间上面）
    if(!tryMove(curPiece,curX,curY))//新块不能移动即游戏结束
    {
        timer.stop();
        isStarted = false;
        bgMusic.stop();
        gameOverSound.play();
    }
}

//开始按钮函数
void CBoard::start()
{
    if(isStarted||isPaused)
        return;

    isStarted = true;
    bgMusic.play();

    numLinesRemoved = 0;//已清除行数初始化
    numPiecesDropped = 0;//已出现的块数初始化
    score = 0;//得分初始化
    level = 1;//游戏难度初始化
    time = 0;//存活时间初始化
    clearBoard();//游戏区域初始化

    //将各种数据给界面
    emit linesRemovedChanged(numLinesRemoved);
    emit scoreChanged(score);
    emit levelChanged(level);
    emit timechange(time);

    newPiece();
    timer.start(timeoutTime(),this);
}

//停止按钮函数
void CBoard::pause()
{
    if(!isStarted)
        return;

    isPaused = !isPaused;

    if(isPaused)
    {
        timer.stop();
        bgMusic.stop();
    }
    else
    {
        timer.start(timeoutTime(),this);
        bgMusic.play();
    }

    update();
}

void CBoard::levelchange()
{   isHard=!isHard;
    if(isHard==true)
        difference=100;
    else
        difference=5000;
}

//判定方块移动函数
bool CBoard::tryMove(const CTetrimino &newPiece, int newX, int newY)
{
    timer.start(timeoutTime(), this);
    for(int i = 0;i < 4; ++i)
    {
        int x = newX + newPiece.x(i);
        int y = newY - newPiece.y(i);

        if(x < 0 || x >= BoardWidth || y < 0 || y >= BoardHeight)//方块越界处理
            return false;
        if(shapeAt(x,y) != NoneShape)//是否有其他方块
            return false;
    }

    //确定可以移动，更新当前的方块
    curPiece = newPiece;
    curX = newX;
    curY = newY;
    update();

    return true;
}

//屏幕清空函数
void CBoard::clearBoard()
{
    for(int i = 0;i < BoardWidth * BoardHeight;++i)
        boardBlocks[i] = NoneShape;
}


void CBoard::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);

    QPainter painter(this);
    QRect rect = contentsRect();

    if(isPaused)
    {
        painter.drawText(rect, Qt::AlignCenter, "暂停中...");
        return;
    }
    int boardTop = rect.bottom() - BoardHeight * squareHeight();

    //绘制现有的方块，把整个Board绘制一下
    for(int i = 0;i < BoardHeight;++i)
    {
        for(int j = 0;j < BoardWidth;++j)
        {
            TetrisShape shape = shapeAt(j, i);
            if(shape != NoneShape)
                drawSquare(painter, rect.left() + j * squareWidth(),
                           rect.bottom() - ( i + 1) * squareHeight(),shape);
        }
    }

    //绘制正在下落的方块
    if(curPiece.shape() != NoneShape)
    {
        for(int i = 0;i < 4;++i)
        {
            int x = curX + curPiece.x(i);
            int y = curY - curPiece.y(i);

            //x,y单位是块，draw里单位是像素
            drawSquare(painter, rect.left() + x * squareWidth()
                       , boardTop + (BoardHeight - y - 1) * squareHeight()
                       , curPiece.shape());
        }
    }
}


void CBoard::drawSquare(QPainter &painter, int x, int y, TetrisShape shape)
{
    static constexpr QRgb colorTable[8]
    {
        0x000000,0xCC6666,0x66CC66,0x6666CC,
        0xCCCC66,0xCC66CC,0x66CCCC,0xDAAA00
    };//方块颜色设置，可根据爱好修改(16进制)

    QColor color = colorTable[shape];
    painter.fillRect(x + 1, y + 1, squareWidth() - 2, squareHeight() - 2, color);

    //方块描边
    painter.setPen(color.lighter());
    painter.drawLine(x, y, x + squareWidth(), y);
    painter.drawLine(x + squareWidth() - 1, y, x + squareWidth() - 1, y + squareHeight());
    painter.setPen(color.darker());
    painter.drawLine(x + squareWidth(), y + squareHeight() - 1, x, y + squareHeight() - 1);
    painter.drawLine(x, y + squareHeight(), x, y);
}

//下移一行函数
void CBoard::oneLineDown()
{
    if(!tryMove(curPiece, curX, curY - 1))//如果碰到底部或其他方块
        pieceDropped(0);
}

//处理落下块函数
void CBoard::pieceDropped(int dropHeight)
{
    downSound.play();
    for(int i = 0;i < 4;++i)
    {
        int x = curX + curPiece.x(i);
        int y = curY - curPiece.y(i);
        shapeAt(x,y) = curPiece.shape();//更新boardBlocks数组
    }

    ++numPiecesDropped;//值决定游戏难度
    if(numPiecesDropped % NextLevelNumber == 0)
    {
        ++level;
        timer.start(timeoutTime(), this);
        emit levelChanged(level);//传值
    }

    score += dropHeight + DropScore;//打分规则
    emit scoreChanged(score);
    removeFullLines();//消除满的行
    newPiece();
}

//处理键盘输入
void CBoard::keyPressEvent(QKeyEvent *event)
{
    if(!isStarted || isPaused || curPiece.shape() == NoneShape)
    {
        QFrame::keyPressEvent(event);
        return;
    }

    switch(event->key()){
    case Qt::Key_Left://左键
        tryMove(curPiece, curX - 1, curY);
        break;
    case Qt::Key_Right://右键
        tryMove(curPiece, curX + 1, curY);
        break;
    case Qt::Key_Shift://shift键顺时针旋转
        tryMove(curPiece.rotatedRight(), curX, curY);
        break;
    case Qt::Key_Up://上键逆时针旋转
        tryMove(curPiece.rotatedLeft(), curX, curY);
        break;
    case Qt::Key_Down://立即下降一行
        oneLineDown();
        break;
    case Qt::Key_Space://直接下落
        dropDown();
        break;
    case Qt::Key_X:
        removeFullLines_Nocondition();
    default:
        QFrame::keyPressEvent(event);
    }
}

//消除满块的行
void CBoard::removeFullLines()
{
    int numFullLines=0;

    //满行检测循环
    for(int i = BoardHeight - 1;i >= 0;--i)
    {
        bool lineIsFull = true;

        for(int j = 0;j < BoardWidth;++j)//扫描一行
        {
            if(shapeAt(j,i) == NoneShape)
            {
                lineIsFull = false;
                break;
            }
        }

        if(lineIsFull)
        {
            //消除一行
            removeSound.play();
            ++numFullLines;

            // 将上方所有行下移一行
            for(int k = i;k < BoardHeight - 1;++k)
            {
                for(int j = 0;j < BoardWidth;++j)
                {
                    shapeAt(j,k) = shapeAt(j,k+1);
                }
            }
            //最高处可能原先也有形状
            for(int j = 0;j < BoardWidth;++j)
                shapeAt(j, BoardHeight - 1) = NoneShape;

            con -> setText(contents[QRandomGenerator::global()->bounded(5)]);
        }
    }

    //分数系统
    if(numFullLines > 0){
        numLinesRemoved += numFullLines;//记录被移除的总行数
        score += 10 * numFullLines;//每消除一行得到十分
        emit linesRemovedChanged(numLinesRemoved);
        emit scoreChanged(score);
    }
}

//无条件消行函数(作弊键，扣10分，不计入消除行数)
void CBoard::removeFullLines_Nocondition()
{
    //消除一行音乐
    removeSound.play();

    //扣分判定
    if(score >= 10)
    {
        score -= 10;//每按一次扣掉十分
        emit scoreChanged(score);
    }
    else
    {
        return;
    }

    // 将上方所有行下移一行
    for(int k = 0;k < BoardHeight - 1;++k)
    {
        for(int j = 0;j < BoardWidth;++j)
        {
            shapeAt(j,k) = shapeAt(j,k+1);
        }
    }
    //最高处可能原先也有形状
    for(int j = 0;j < BoardWidth;++j)
        shapeAt(j, BoardHeight - 1) = NoneShape;
}

//当前方块掉落到最低位置并固定
void CBoard::dropDown()
{
    int newY = curY;
    int dropHeight = 0;

    //掉落循环
    while(newY > 0){
        if(!tryMove(curPiece, curX, newY-1))
            break;

        --newY;
        ++dropHeight;
    }

    pieceDropped(dropHeight);//处理方块掉落后的操作
}

//时间变化事件
void CBoard::timerEvent(QTimerEvent *event)
{
    if(isStarted && !isPaused)
    {
        oneLineDown();//下移一行

        if((event->timerId() == id && !isPaused))
        {
            time += 1;//每秒存活时间加一
        }

        if(event->timerId() == id_1 && !isPaused)
        {
            con -> setText("");
        }
        emit timechange(time);
    }
}


