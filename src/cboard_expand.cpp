#include "cboard_expand.h"
#include <QLabel>
#include <QPainter>
#include <QKeyEvent>
#include <QRandomGenerator>
#include "QBasicTimer"

CBoard_Expand::CBoard_Expand(QWidget *parent):QFrame(parent)
{
    //随机生成方块
    nextPiece_Expand.setRandomShape_Expand();
    clearBoard_Expand();
    setFocusPolicy(Qt::StrongFocus);
}

//记录方块信息
void CBoard_Expand::setNextPieceLabel_Expand(QLabel *label)
{
    nextPieceLabel_Expand = label;
}

//创建信息对应的图片
void CBoard_Expand::showNextPiece_Expand()
{
    if(!nextPieceLabel_Expand)
        return;//指针为空进行返回

    //确定图片大小（求具体宽度）（单位：块）
    int dx = nextPiece_Expand.maxX_Expand() - nextPiece_Expand.minX_Expand() + 1;
    int dy = nextPiece_Expand.maxY_Expand() - nextPiece_Expand.minY_Expand() + 1;

    //绘图（单位：像素）
    QPixmap pixmap(dx * squareWidth_Expand(), dy * squareHeight_Expand());//块数乘以每块像素数
    QPainter painter(&pixmap);
    painter.fillRect(pixmap.rect(), QColor(3, 54, 73));

    //绘制八个小块
    //以左上角为（0,0）点
    for(int i = 0;i < 8;++i)
    {
        int x = nextPiece_Expand.x_Expand(i) - nextPiece_Expand.minX_Expand();
        int y = nextPiece_Expand.y_Expand(i) - nextPiece_Expand.minY_Expand();
        drawSquare_Expand(painter, x * squareWidth_Expand(), y * squareHeight_Expand(), nextPiece_Expand.shape_Expand());
    }

    nextPieceLabel_Expand->setPixmap(pixmap);
}

//处理新块
void CBoard_Expand::newPiece_Expand()
{
    curPiece_Expand = nextPiece_Expand;
    nextPiece_Expand.setRandomShape_Expand();
    showNextPiece_Expand();
    curX_Expand = BoardWidth_Expand / 2;
    curY_Expand = BoardHeight_Expand - 1 + curPiece_Expand.minY_Expand();

    //把当前块摆放到起始位置（中间上面）
    if(!tryMove_Expand(curPiece_Expand, curX_Expand, curY_Expand))//新块不能移动即游戏结束
    {
        timer.stop();
        isStarted_Expand = false;
    }
}

//屏幕清空函数
void CBoard_Expand::clearBoard_Expand()
{
    for(int i = 0;i < BoardWidth_Expand * BoardHeight_Expand;++i)
        boardBlocks_Expand[i] = NoneShape;
}

void CBoard_Expand::drawSquare_Expand(QPainter &painter, int x, int y, TetrisShape_Expand shape)
{
    static constexpr QRgb colorTable_Expand[8]
        {
            0x000000,0xCC6666,0x66CC66,0x6066CC,
            0xCBCC66,0xAC68CC,0x66CCDC,0xDA5A00
        };//方块颜色设置，可根据爱好修改(16进制)

    QColor color = colorTable_Expand[shape];
    painter.fillRect(x + 1, y + 1, squareWidth_Expand() - 2, squareHeight_Expand() - 2, color);

    //方块描边
    painter.setPen(color.lighter());
    painter.drawLine(x, y, x + squareWidth_Expand(), y);
    painter.drawLine(x + squareWidth_Expand() - 1, y, x + squareWidth_Expand() - 1, y + squareHeight_Expand());
    painter.setPen(color.darker());
    painter.drawLine(x + squareWidth_Expand(), y + squareHeight_Expand() - 1, x, y + squareHeight_Expand() - 1);
    painter.drawLine(x, y + squareHeight_Expand(), x, y);
}

bool CBoard_Expand::tryMove_Expand(const CTetrimino_Expand &newPiece_Expand, int newX_Expand, int newY_Expand)
{
    for(int i = 0;i < 8; ++i)
    {
        int x = newX_Expand + newPiece_Expand.x_Expand(i);
        int y = newY_Expand - newPiece_Expand.y_Expand(i);

        if(x < 0 || x >= BoardWidth_Expand || y < 0 || y >= BoardHeight_Expand)//方块越界处理
            return false;
        if(shapeAt_Expand(x,y) != NoneShape)//是否有其他方块
            return false;
    }

    //确定可以移动，更新当前的方块
    curPiece_Expand = newPiece_Expand;
    curX_Expand = newX_Expand;
    curY_Expand = newY_Expand;
    update();

    return true;
}

int CBoard_Expand::timeoutTime_Expand()
{
    return 1000;
}

//下移一行函数
void CBoard_Expand::oneLineDown_Expand()
{
    if(!tryMove_Expand(curPiece_Expand, curX_Expand, curY_Expand - 1))//如果碰到底部或其他方块
        pieceDropped_Expand();
}

void CBoard_Expand::pieceDropped_Expand()
{
    for(int i = 0;i < 8;++i)
    {
        int x = curX_Expand + curPiece_Expand.x_Expand(i);
        int y = curY_Expand - curPiece_Expand.y_Expand(i);
        shapeAt_Expand(x,y) = curPiece_Expand.shape_Expand();//更新boardBlocks数组
    }

    removeFullLines_Expand();//消除满的行
    newPiece_Expand();
}

void CBoard_Expand::removeFullLines_Expand()
{
    //满行检测循环
    for(int i = BoardHeight_Expand - 1;i >= 0;--i)
    {
        bool lineIsFull = true;

        for(int j = 0;j < BoardWidth_Expand;++j)//扫描一行
        {
            if(shapeAt_Expand(j,i) == NoneShape)
            {
                lineIsFull = false;
                break;
            }
        }

        if(lineIsFull)
        {
            // 将上方所有行下移一行
            for(int k = i;k < BoardHeight_Expand - 1;++k)
            {
                for(int j = 0;j < BoardWidth_Expand;++j)
                {
                    shapeAt_Expand(j,k) = shapeAt_Expand(j,k+1);
                }
            }

            //最高处可能原先也有形状
            for(int j = 0;j < BoardWidth_Expand;++j)
                shapeAt_Expand(j, BoardHeight_Expand - 1) = NoneShape;
        }
    }

}

//当前方块掉落到最低位置并固定
void CBoard_Expand::dropDown_Expand()
{
    int newY = curY_Expand;

    //掉落循环
    while(newY > 0){
        if(!tryMove_Expand(curPiece_Expand, curX_Expand, newY - 1))
            break;

        --newY;
    }

    pieceDropped_Expand();//处理方块掉落后的操作
}

void CBoard_Expand::start()
{    if(isStarted_Expand)
        return;

    isStarted_Expand = true;


    clearBoard_Expand();//游戏区域初始化

    newPiece_Expand();
    timer.start(timeoutTime_Expand(),this);
}


//处理键盘输入
void CBoard_Expand::keyPressEvent(QKeyEvent *event)
{
    if(!isStarted_Expand || curPiece_Expand.shape_Expand() == NoneShape)
    {
        QFrame::keyPressEvent(event);
        return;
    }

    switch(event->key()){
    case Qt::Key_Left://左键
        tryMove_Expand(curPiece_Expand, curX_Expand - 1, curY_Expand);
        break;
    case Qt::Key_Right://右键
        tryMove_Expand(curPiece_Expand, curX_Expand + 1, curY_Expand);
        break;
    case Qt::Key_Shift://shift键顺时针旋转
        tryMove_Expand(curPiece_Expand.rotatedRight_Expand(), curX_Expand, curY_Expand);
        break;
    case Qt::Key_Up://上键逆时针旋转
        tryMove_Expand(curPiece_Expand.rotatedLeft_Expand(), curX_Expand, curY_Expand);
        break;
    case Qt::Key_Down://立即下降一行
        oneLineDown_Expand();
        break;
    case Qt::Key_Space://直接下落
        dropDown_Expand();
        break;
    default:
        QFrame::keyPressEvent(event);
    }
}


void CBoard_Expand::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);

    QPainter painter(this);
    QRect rect = contentsRect();

    int boardTop = rect.bottom() - BoardHeight_Expand * squareHeight_Expand();

    //绘制现有的方块，把整个Board绘制一下
    for(int i = 0;i < BoardHeight_Expand;++i)
    {
        for(int j = 0;j < BoardWidth_Expand;++j)
        {
            TetrisShape_Expand shape = shapeAt_Expand(j, i);
            if(shape != NoneShape)
                drawSquare_Expand(painter, rect.left() + j * squareWidth_Expand(),
                           rect.bottom() - ( i + 1) * squareHeight_Expand(), shape);
        }
    }

    //绘制正在下落的方块
    if(curPiece_Expand.shape_Expand() != NoneShape)
    {
        for(int i = 0;i < 8;++i)
        {
            int x = curX_Expand + curPiece_Expand.x_Expand(i);
            int y = curY_Expand - curPiece_Expand.y_Expand(i);

            //x,y单位是块，draw里单位是像素
            drawSquare_Expand(painter, rect.left() + x * squareWidth_Expand()
                       , boardTop + (BoardHeight_Expand - y - 1) * squareHeight_Expand()
                       , curPiece_Expand.shape_Expand());
        }
    }
}

void CBoard_Expand::timerEvent(QTimerEvent *event)
{
    if(isStarted_Expand)
        oneLineDown_Expand();//下移一行
}

