#include "higherplay.h"
#include "ui_higherplay.h"
#include "cboard_expand.h"
#include <QMouseEvent>

HigherPlay::HigherPlay(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HigherPlay)
{
    ui->setupUi(this);

    ui->frameTetrisBoard_1->setNextPieceLabel_Expand(ui->labelNextPiece_1);

    connect(ui->pbStart, &QPushButton::clicked, ui->frameTetrisBoard_1, &CBoard_Expand::start);

    ui->pbStart->setFocusPolicy(Qt::NoFocus);
}

HigherPlay::~HigherPlay()
{
    delete ui;
}
