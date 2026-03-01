#include "waychoice.h"
#include "ui_waychoice.h"
#include "higherplay.h"

WayChoice::WayChoice(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WayChoice)
{
    ui->setupUi(this);
}

WayChoice::~WayChoice()
{
    delete ui;
}

void WayChoice::on_Way_1_clicked()
{
    higherplay = new HigherPlay();
    higherplay->show();
    this->hide();
}


void WayChoice::on_Way_2_clicked()
{
    numberplay = new NumberPlay();
    numberplay->show();
    this->hide();
}

