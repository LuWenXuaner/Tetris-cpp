/********************************************************************************
** Form generated from reading UI file 'numberplay.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUMBERPLAY_H
#define UI_NUMBERPLAY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <cboard_number.h>

QT_BEGIN_NAMESPACE

class Ui_NumberPlay
{
public:
    QFrame *frame;
    QPushButton *pbStart;
    QLabel *label;
    QLabel *labelNextPiece;
    CBoard_Number *frameNumberTetris;

    void setupUi(QWidget *NumberPlay)
    {
        if (NumberPlay->objectName().isEmpty())
            NumberPlay->setObjectName("NumberPlay");
        NumberPlay->resize(494, 590);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/ngame.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        NumberPlay->setWindowIcon(icon);
        NumberPlay->setStyleSheet(QString::fromUtf8("*{\n"
"	border-style:double;\n"
"	border-color: rgb(0, 240, 0);\n"
"	border-width:4px;\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius:10px;\n"
"	font: 700 16pt \"Microsoft YaHei UI\";\n"
"	pading:4px;\n"
"	min-height:50px;\n"
"}\n"
"\n"
"QFrame#frame{\n"
"	background-color: rgb(3, 54, 73);\n"
"}\n"
"\n"
"QLabel{\n"
"	border-width:0px;\n"
"}\n"
"\n"
"QLabel#labelNextPiece{\n"
"	border-width:2px;\n"
"}\n"
"\n"
"QFrame#frameTetrisBoard{\n"
"	background-image: url(:/image/tetrisbg.png);\n"
"	pading:0px;\n"
"}\n"
"\n"
"QPushButton{\n"
"	border-width:1px;\n"
"	font: 14pt \"Microsoft YaHei UI\";\n"
"}\n"
"QPushButton:hover{\n"
"	font: 16pt \"Microsoft YaHei UI\";\n"
"}\n"
"QPushButton:pressed{\n"
"	padding-left:6px;\n"
"	pading-top:6px;\n"
"	font: 14pt \"Microsoft YaHei UI\";\n"
"}"));
        frame = new QFrame(NumberPlay);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 501, 621));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pbStart = new QPushButton(frame);
        pbStart->setObjectName("pbStart");
        pbStart->setGeometry(QRect(350, 480, 141, 101));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(350, 30, 121, 51));
        label->setAlignment(Qt::AlignCenter);
        labelNextPiece = new QLabel(frame);
        labelNextPiece->setObjectName("labelNextPiece");
        labelNextPiece->setGeometry(QRect(350, 90, 131, 121));
        labelNextPiece->setAlignment(Qt::AlignCenter);
        frameNumberTetris = new CBoard_Number(frame);
        frameNumberTetris->setObjectName("frameNumberTetris");
        frameNumberTetris->setGeometry(QRect(10, 10, 331, 571));
        frameNumberTetris->setFrameShape(QFrame::StyledPanel);
        frameNumberTetris->setFrameShadow(QFrame::Raised);

        retranslateUi(NumberPlay);

        QMetaObject::connectSlotsByName(NumberPlay);
    } // setupUi

    void retranslateUi(QWidget *NumberPlay)
    {
        NumberPlay->setWindowTitle(QCoreApplication::translate("NumberPlay", "NumberPlay", nullptr));
        pbStart->setText(QCoreApplication::translate("NumberPlay", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        label->setText(QCoreApplication::translate("NumberPlay", "\344\270\213\344\270\200\344\270\252\346\226\271\345\235\227\357\274\232", nullptr));
        labelNextPiece->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NumberPlay: public Ui_NumberPlay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUMBERPLAY_H
