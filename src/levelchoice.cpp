#include "levelchoice.h"
#include "ui_levelchoice.h"
#include "setwindow.h"

LevelChoice::LevelChoice(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LevelChoice)
{
    ui->setupUi(this);
    //connect(ui->pushButton,&QPushButton::clicked,
            //,&CBoard::one);
    //connect(ui->pushButton_2,&QPushButton::clicked,
            //ui->frame,&CBoard::two);
    //connect(ui->pushButton_3,&QPushButton::clicked,
           // ui->frame,&CBoard::three);
    connect(ui->Take, SIGNAL(clicked()), this, SLOT(ReturnSetting()));
}

LevelChoice::~LevelChoice()
{
    delete ui;
}

void LevelChoice::ReturnSetting()
{
    emit ReturnSignal();
    this->hide();
}


