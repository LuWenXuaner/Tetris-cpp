#ifndef CBOARD_H
#define CBOARD_H

#include <QFrame>
#include <QPointer>
#include "CTetrimino.h"
#include <QBasicTimer>
#include <QMediaPlayer>
#include <QSoundEffect>
#include <QAudioOutput>

class QLabel;

class CBoard : public QFrame
{
    Q_OBJECT
private:
    QPointer<QLabel> nextPieceLabel;
    QPointer<QLabel> con;

    QString contents[5] = {"Good!", "Very Good!", "Excellent!", "继续加油", "继续保持！"};

    enum
    {
        DropScore = 7, BoardWidth = 16, BoardHeight = 30, NextLevelNumber = 20
    };

    //记录下一个方块
    CTetrimino nextPiece;

    //记录当前方块
    CTetrimino curPiece;
    int curX;
    int curY;

    //整个游戏区域
    TetrisShape boardBlocks[BoardWidth * BoardHeight];

    //判断是否暂停与开始
    bool isStarted = false;
    bool isPaused = false;
    bool isHard=false;
    //设置初始值
    int numLinesRemoved = 0;
    int numPiecesDropped = 0;
    int score = 0;
    int level = 1;
    int time = 0;
    int difference = 5000;

    //定时器
    QBasicTimer timer;
    int id = startTimer(1000);
    int id_1 = startTimer(3000);

    //音乐
    QMediaPlayer bgMusic;
    QAudioOutput audioOutput;
    QSoundEffect removeSound;
    QSoundEffect downSound;
    QSoundEffect gameOverSound;

private:

    //计算出格子的长宽
    int squareWidth()
    {
        return contentsRect().width() / BoardWidth;
    }
    int squareHeight()
    {
        return contentsRect().height() / BoardHeight;
    }

    //移动的函数
    bool tryMove(const CTetrimino &newPiece, int newX, int newY);

    //返回所在的位置
    TetrisShape& shapeAt(int x, int y)
    {
        return boardBlocks[y * BoardWidth + x];
    }

    //屏幕清空函数
    void clearBoard();

    //显示下一块的形状
    void showNextPiece();

    //绘制小块
    void drawSquare(QPainter& painter, int x, int y, TetrisShape shape);

    //下降一行
    void oneLineDown();

    //下降到底
    void pieceDropped(int dropHeight);

    //每次下降的间隔(值越小难度越高)
    int timeoutTime()
    {
        return difference/(level + 1);
    }

    //消除行
    void removeFullLines();

    //无条件消行
    void removeFullLines_Nocondition();

    //方块停下
    void dropDown();

    //生成新的块
    void newPiece();

    void setSimple(int v);

protected:
    void paintEvent(QPaintEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

public:
    CBoard(QWidget* parent = nullptr);

    //用于接收下一方块的信号
    void setNextPieceLabel(QLabel* label);

    void setContent(QLabel *con);

public slots:
    //开始和终止的槽函数
    void start();
    void pause();
    void levelchange();


signals:
    //改变数字的信号
    void levelChanged(int level);
    void scoreChanged(int score);
    void linesRemovedChanged(int numLines);
    void timechange(int time);
};

#endif // CBOARD_H
