#include "numberplay.h"
#include "ui_numberplay.h"
#include <QMouseEvent>
#include "cboard_number.h"

NumberPlay::NumberPlay(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NumberPlay)
{
    ui->setupUi(this);
    ui->frameNumberTetris->setNextPieceLabel(ui->labelNextPiece);

    connect(ui->pbStart, &QPushButton::clicked, ui->frameNumberTetris, &CBoard_Number::start);
    ui->pbStart->setFocusPolicy(Qt::NoFocus);
}

NumberPlay::~NumberPlay()
{
    delete ui;
}
