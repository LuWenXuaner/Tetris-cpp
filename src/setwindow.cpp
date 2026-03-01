#include "setwindow.h"
#include "ui_setwindow.h"
#include <QApplication>
#include "CBoard.h"

SetWindow::SetWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SetWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("Setting"));
}

SetWindow::~SetWindow()
{
    delete ui;
}

void SetWindow::on_ReturnMain_clicked()
{
    emit Return_signal();
    close();
}


void SetWindow::ShowSetting()
{
    this->show();
}


void SetWindow::on_WayChoose_clicked()
{
    waychoice = new WayChoice();
    waychoice->show();
    this->hide();
}


