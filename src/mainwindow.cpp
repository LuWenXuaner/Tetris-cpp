#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include "setwindow.h"
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SetInterface = new SetWindow();

    setWindowFlag(Qt::FramelessWindowHint);//无边框，无法移动
    setAttribute(Qt::WA_TranslucentBackground,true);

    ui->frameTetrisBoard->setNextPieceLabel(ui->labelNextPiece);
    ui->frameTetrisBoard->setContent(ui->Contents);

    connect(ui->pbStart,&QPushButton::clicked,
            ui->frameTetrisBoard,&CBoard::start);
    connect(ui->pbPause,&QPushButton::clicked,
            ui->frameTetrisBoard,&CBoard::pause);
    connect(ui->level,&QPushButton::clicked,
            ui->frameTetrisBoard,&CBoard::levelchange);

    connect(ui->frameTetrisBoard,&CBoard::scoreChanged,
            ui->lcdScore,qOverload<int>(&QLCDNumber::display));
    connect(ui->frameTetrisBoard,&CBoard::levelChanged,
            ui->lcdLevel,qOverload<int>(&QLCDNumber::display));
    connect(ui->frameTetrisBoard,&CBoard::linesRemovedChanged,
            ui->lcdRemoved,qOverload<int>(&QLCDNumber::display));
    connect(ui->frameTetrisBoard,&CBoard::timechange,
            ui->lcdTime,qOverload<int>(&QLCDNumber::display));

    ui->pbStart->setFocusPolicy(Qt::NoFocus);
    ui->pbPause->setFocusPolicy(Qt::NoFocus);
    ui->pbExit->setFocusPolicy(Qt::NoFocus);

    connect(ui->pbSet, &QPushButton::clicked, ui->frameTetrisBoard, &CBoard::pause);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
   QPoint mousePos = event->globalPosition().toPoint();//鼠标相对于整个屏幕
   QPoint topLeft = geometry().topLeft();//窗口相对于整个屏幕
   winPos = mousePos - topLeft;
}

void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    winPos = QPoint();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint mousePos = event->globalPosition().toPoint();//鼠标相对于整个屏幕
    QPoint endPos = mousePos-winPos;
    move(endPos);
}

void MainWindow::on_pbPause_clicked()
{
    if(ui->pbPause->text() == QString("暂 停"))
        ui->pbPause->setText(QString("恢 复"));
    else
        ui->pbPause->setText(QString("暂 停"));
}


void MainWindow::on_pbSet_clicked()
{

    connect(this->SetInterface, SIGNAL(Return_signal()), this, SLOT(GoStarted()));
    connect(ui->pbSet, &QPushButton::clicked, ui->frameTetrisBoard, &CBoard::pause);

    if(ui->pbPause->text() == QString("暂 停"))
    {
        ui->pbPause->setText(QString("恢 复"));
        connect(ui->pbSet, &QPushButton::clicked, ui->frameTetrisBoard, &CBoard::pause);
    }

    SetInterface->show();
    this->hide();

}

void MainWindow::GoStarted()
{
    this->show();
    this->on_pbPause_clicked();

    if(ui->pbPause->text() == QString("暂 停"))
        ui->pbPause->setText(QString("恢 复"));
}

void MainWindow::on_level_clicked()
{    if(ui->level->text() == QString("困 难"))
        ui->level->setText(QString("简 单"));
    else
        ui->level->setText(QString("困 难"));

}

