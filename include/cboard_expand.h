#ifndef CBOARD_EXPAND_H
#define CBOARD_EXPAND_H

#include <QBasicTimer>
#include <QFrame>
#include <QPointer>
#include "ctetrimino_expand.h"
#include <qtimer.h>

class QLabel;

class CBoard_Expand: public QFrame
{
    Q_OBJECT
public:
    CBoard_Expand(QWidget* parent = nullptr);

    //用于接收下一方块的信号
    void setNextPieceLabel_Expand(QLabel* label);

    //显示下一块的形状
    void showNextPiece_Expand();

private:
    enum
    {
         BoardWidth_Expand = 24, BoardHeight_Expand = 40
    };

    //记录当前方块
    CTetrimino_Expand curPiece_Expand;
    int curX_Expand;
    int curY_Expand;

    //整个游戏区域
    TetrisShape_Expand boardBlocks_Expand[BoardWidth_Expand * BoardHeight_Expand];

    //判断是否开始
    bool isStarted_Expand = false;

    //定时器
    QBasicTimer timer;
private:
    QPointer<QLabel> nextPieceLabel_Expand;
    CTetrimino_Expand nextPiece_Expand;

    //计算出格子的长宽
    int squareWidth_Expand()
    {
        return contentsRect().width() / BoardWidth_Expand;
    }
    int squareHeight_Expand()
    {
        return contentsRect().height() / BoardHeight_Expand;
    }

    //生成新的块
    void newPiece_Expand();

    //屏幕清空函数
    void clearBoard_Expand();

    //返回所在的位置
    TetrisShape_Expand& shapeAt_Expand(int x, int y)
    {
        return boardBlocks_Expand[y * BoardWidth_Expand + x];
    }

    //绘制小块
    void drawSquare_Expand(QPainter& painter, int x, int y, TetrisShape_Expand shape);

    //移动的函数
    bool tryMove_Expand(const CTetrimino_Expand &newPiece_Expand, int newX_Expand, int newY_Expand);

    //每次下降的间隔(值越小难度越高)
    int timeoutTime_Expand();


    //下降一行
    void oneLineDown_Expand();

    //下降到底
    void pieceDropped_Expand();

    //消除行
    void removeFullLines_Expand();

    //方块停下
    void dropDown_Expand();


public slots:
    //开始槽函数
    void start();

protected:
    void timerEvent(QTimerEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
};

#endif // CBOARD_EXPAND_H
