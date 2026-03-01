#ifndef CBOARD_NUMBER_H
#define CBOARD_NUMBER_H

#include <QBasicTimer>
#include <QFrame>
#include <QPointer>
#include <qtimer.h>
#include "ctetrimino_number.h"

class QLabel;

class CBoard_Number: public QFrame
{
    Q_OBJECT
public:
    CBoard_Number(QWidget* parent = nullptr);
    void setNextPieceLabel(QLabel* label);

public slots:
    //开始的槽函数
    void start();

private:
    enum{
        BoardWidth=20,BoardHeight=36
    };

    //计算出格子的长宽
    int squareWidth(){return contentsRect().width()/BoardWidth;}
    int squareHeight(){return contentsRect().height()/BoardHeight;}

    //移动的函数
    bool tryMove(const CTetrimino_Number &newPiece,int newX, int newY);

    //返回所在的位置
    int&  numberat(int x,int y){
        return block[y*BoardWidth+x];
    }

    TetrisShape& shapeAt(int x,int y){
        return boardBBlocks[y*BoardWidth+x];
    }

    void clearBoard();

    //显示下一块的形状
    void showNextPiece();

    //绘制小块
    void drawSquare(QPainter& painter,int x, int y, TetrisShape shape, int number);

    //下降一行
    void oneLineDown();

    //下降到底
    void pieceDropped();

    //每次下降的间隔
    int timeoutTime(){return 1000;}

    //消除行
    void removeFullLines();

    //方块停下
    void dropDown();

    //生成新的块
    void newPiece();
private:
    QPointer<QLabel> nextPieceLabel;

    //记录下一个方块
    CTetrimino_Number nextPiece;

    //记录当前方块
    CTetrimino_Number curPiece;
    int curX;
    int curY;

    //整个游戏区域
    TetrisShape boardBBlocks[BoardWidth*BoardHeight];
    int block[BoardHeight*BoardWidth];
    bool isStarted=false;

    //设置初始值
    int numLinesRemoved=0;

    //判断是否暂停与开始
    int nsaver[4];
    int csaver[4];

    //定时器
    QBasicTimer timer;
protected:
    void paintEvent(QPaintEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // CBOARD_NUMBER_H
