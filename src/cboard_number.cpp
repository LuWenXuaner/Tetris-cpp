#include "cboard_number.h"
#include <QLabel>
#include <QPainter>
#include <QKeyEvent>
#include <QRandomGenerator>
#include "QBasicTimer"

CBoard_Number::CBoard_Number(QWidget *parent):QFrame(parent)
{   //随机生成方块

    nextPiece.setRandomShape();
    clearBoard();
    setFocusPolicy(Qt::StrongFocus);

}

//记录方块信息
void CBoard_Number::setNextPieceLabel(QLabel *label)
{
    nextPieceLabel=label;
}

void CBoard_Number::showNextPiece()
{
    if(!nextPieceLabel) return;
    //单位：小块
    int dx=nextPiece.maxX()-nextPiece.minX()+1;
    int dy=nextPiece.maxY()-nextPiece.minY()+1;
    //单位：像素
    QPixmap pixmap(dx*squareWidth(),dy*squareHeight());
    QPainter painter(&pixmap);
    painter.fillRect(pixmap.rect(),QColor(3, 54, 73));
    //绘制四个小块
    for(int i=0;i<4;++i){
        int x=nextPiece.x(i)-nextPiece.minX();
        int y=nextPiece.y(i)-nextPiece.minY();
        drawSquare(painter,x*squareWidth(),y*squareHeight()
                   ,nextPiece.shape(), nextPiece.mun(i));

        nsaver[i]=nextPiece.mun(i);
    }
    nextPieceLabel->setPixmap(pixmap);
}

void CBoard_Number::newPiece()
{
    for(int i=0;i<4;i++)
    {
        nsaver[i]=nextPiece.mun(i);

    }

    for(int i=0;i<4;i++)
    {
        csaver[i]=nsaver[i];
    }

    curPiece=nextPiece;
    nextPiece.setRandomShape();

    for(int i=0;i<4;i++)
    {
        nsaver[i]=nextPiece.mun(i);
    }

    showNextPiece();

    curX=BoardWidth/2;
    curY=BoardHeight-1+curPiece.minY();

    //尝试把newPiece（curPiece）摆放到起始位置（中间，上面）
    if(!tryMove(curPiece,curX,curY)){
        //游戏结束
        timer.stop();
        isStarted=false;
    }
}

void CBoard_Number::start()
{
    if(isStarted)
        return;

    isStarted=true;

    numLinesRemoved=0;

    clearBoard();

    newPiece();
    timer.start(timeoutTime(),this);
}


bool CBoard_Number::tryMove(const CTetrimino_Number &newPiece, int newX, int newY)
{
    //判定是否可以移动
    for(int i=0; i<4; ++i)
    {
        int x=newX+newPiece.x(i);
        int y=newY-newPiece.y(i);
        if(x<0||x>=BoardWidth||y<0||y>=BoardHeight)
            return false;
        //是否有其他方块
        if(shapeAt(x,y)!=NoShape)
            return false;
    }

    //确定可以移动，更新当前的方块
    curPiece=newPiece;//旋转时，需要
    curX=newX;
    curY=newY;

    update();

    return true;
}

void CBoard_Number::clearBoard()
{
    for(int i=0;i<BoardWidth*BoardHeight;++i)
    {
        boardBBlocks[i]=NoShape;
        block[i]=0;
    }
}

void CBoard_Number::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);

    QPainter painter(this);
    QRect rect=contentsRect();

    int boardTop=rect.bottom()-BoardHeight*squareHeight();
    // 绘制现有的方块（保持不变，不绘制数字）
    for (int i = 0; i < BoardHeight; ++i)
        for (int j = 0; j < BoardWidth; ++j)
        {
            TetrisShape shape = shapeAt(j, i);
            if (shape != NoShape)
                drawSquare(painter, rect.left() + j * squareWidth(),
                           rect.bottom() - (i + 1) * squareHeight(), shape, numberat(j,i));
        }

    // 绘制正在下落的方块，并为其绘制数字（假设数字为方块索引+1）
    if (curPiece.shape() != NoShape)
    {
        for (int i = 0; i < 4; ++i)
        {
            int x = curX + curPiece.x(i);
            int y = curY - curPiece.y(i);
            // 假设我们为每个方块分配一个从1到4的数字
            drawSquare(painter, rect.left() + x * squareWidth(),
                       boardTop + (BoardHeight - y - 1) * squareHeight(),
                       curPiece.shape(), csaver[i]);
        }
    }
}

void CBoard_Number::drawSquare(QPainter &painter, int x, int y, TetrisShape shape,int number)
{
    static constexpr QRgb colorTable[8]
    {
        0x000000,0xCC6666,0x66CC66,0x6666CC,
        0xCCCC66,0xCC66CC,0x66CCCC,0xDAAA00
    };

    QColor color=colorTable[shape];
    painter.fillRect(x+1,y+1,squareWidth()-2,squareHeight()-2,color);

    //描边
    painter.setPen(color.lighter());
    painter.drawLine(x,y,x+squareWidth(),y);
    painter.drawLine(x+squareWidth()-1,y,x+squareWidth()-1,y+squareHeight());
    painter.setPen(color.darker());
    painter.drawLine(x+squareWidth(),y+squareHeight()-1,x,y+squareHeight()-1);
    painter.drawLine(x,y+squareHeight(),x,y);

    QString numberStr = QString::number(number);
    QFont font = painter.font();
    font.setPixelSize(std::max(squareWidth(), squareHeight()) * 0.7); // 根据方块大小调整字体大小
    painter.setFont(font);
    painter.setPen(Qt::white); // 假设使用白色字体，可以根据需要调整
    painter.drawText(QRect(x + 1, y + 1, squareWidth() - 2, squareHeight() - 2),
                     Qt::AlignCenter, numberStr);
}

void CBoard_Number::oneLineDown()
{
    if(!tryMove(curPiece,curX,curY-1))
        pieceDropped();
}

void CBoard_Number::pieceDropped()
{

    for(int i=0;i<4;++i)
    {
        int x=curX+curPiece.x(i);
        int y=curY-curPiece.y(i);
        shapeAt(x,y)=curPiece.shape();//更新boardBlocks数组
        numberat(x,y)=csaver[i];
    }

    removeFullLines();
    newPiece();
}

void CBoard_Number::keyPressEvent(QKeyEvent *event)
{
    if(!isStarted||curPiece.shape()==NoShape)
    {
        QFrame::keyPressEvent(event);
        return;
    }

    switch(event->key())
    {
    case Qt::Key_Left://
        tryMove(curPiece,curX-1,curY);break;
    case Qt::Key_Right:
        tryMove(curPiece,curX+1,curY);break;
    case Qt::Key_Shift:
        tryMove(curPiece.rotatedRight(),curX,curY);break;
    case Qt::Key_Up:
        tryMove(curPiece.rotatedLeft(),curX,curY);break;
    case Qt::Key_Down://立即下降一行
        oneLineDown();break;
    case Qt::Key_Space://直接下落
        dropDown();break;
    default:
        QFrame::keyPressEvent(event);
    }
}

void CBoard_Number::removeFullLines()
{
    int full;

    //消除行s
    for(int i=BoardHeight-1;i>=0;--i)
    {
        bool lineIsFull=true;
        //扫描一行
        for(int j=0;j<BoardWidth;j++)
        {
            if(shapeAt(j,i)==NoShape || (numberat(j,i)!=numberat(j+1,i)&& j<BoardWidth-1) )
            {
                lineIsFull=false;
                break;
            }
            else
                full=i;
        }

        if(lineIsFull)
        {
            //消除一行
            for(int k=full;k<BoardHeight-1;++k)
            {
                for(int j=0;j<BoardWidth;++j)
                {
                    shapeAt(j,k)=shapeAt(j,k+1);
                    numberat(j,k)=numberat(j,k+1);
                }
            }
            //最高处可能原先也有形状
            for(int j=0;j<BoardWidth;++j)
                shapeAt(j,BoardHeight-1)=NoShape;
        }
    }

}

void CBoard_Number::dropDown()
{
    int newY=curY;

    while(newY>0)
    {
        if(!tryMove(curPiece,curX,newY-1))
            break;
        --newY;
    }
    pieceDropped();
}

void CBoard_Number::timerEvent(QTimerEvent *event)
{
    if(isStarted)
        oneLineDown();
}
