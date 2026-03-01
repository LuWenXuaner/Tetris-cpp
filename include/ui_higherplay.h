/********************************************************************************
** Form generated from reading UI file 'higherplay.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIGHERPLAY_H
#define UI_HIGHERPLAY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <cboard_expand.h>

QT_BEGIN_NAMESPACE

class Ui_HigherPlay
{
public:
    QFrame *frameBg_1;
    CBoard_Expand *frameTetrisBoard_1;
    QLabel *label;
    QLabel *labelNextPiece_1;
    QPushButton *pbStart;

    void setupUi(QWidget *HigherPlay)
    {
        if (HigherPlay->objectName().isEmpty())
            HigherPlay->setObjectName("HigherPlay");
        HigherPlay->resize(655, 765);
        HigherPlay->setMinimumSize(QSize(300, 58));
        HigherPlay->setMouseTracking(false);
        HigherPlay->setTabletTracking(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/Way_1.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        HigherPlay->setWindowIcon(icon);
        HigherPlay->setStyleSheet(QString::fromUtf8("*{\n"
"	border-style:double;\n"
"	border-color: rgb(0, 240, 0);\n"
"	border-width:4px;\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius:10px;\n"
"	font: 700 16pt \"Microsoft YaHei UI\";\n"
"	pading:4px;\n"
"	min-height:50px;\n"
"	font: 18pt \"\351\273\221\344\275\223\";\n"
"}\n"
"\n"
"QFrame#frameBg_1{\n"
"	background-color: rgb(3, 54, 73);\n"
"}\n"
"\n"
"QLabel{\n"
"	border-width:0px;\n"
"}\n"
"\n"
"QLabel#labelNextPiece_1{\n"
"	border-width:2px;\n"
"}\n"
"\n"
"QFrame#frameTetrisBoard_1{\n"
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
        frameBg_1 = new QFrame(HigherPlay);
        frameBg_1->setObjectName("frameBg_1");
        frameBg_1->setGeometry(QRect(0, 0, 651, 761));
        frameBg_1->setFrameShape(QFrame::StyledPanel);
        frameBg_1->setFrameShadow(QFrame::Raised);
        frameTetrisBoard_1 = new CBoard_Expand(frameBg_1);
        frameTetrisBoard_1->setObjectName("frameTetrisBoard_1");
        frameTetrisBoard_1->setGeometry(QRect(10, 10, 441, 741));
        frameTetrisBoard_1->setMinimumSize(QSize(300, 58));
        frameTetrisBoard_1->setBaseSize(QSize(300, 58));
        frameTetrisBoard_1->setFrameShape(QFrame::StyledPanel);
        frameTetrisBoard_1->setFrameShadow(QFrame::Raised);
        label = new QLabel(frameBg_1);
        label->setObjectName("label");
        label->setGeometry(QRect(490, 30, 141, 51));
        label->setAlignment(Qt::AlignCenter);
        labelNextPiece_1 = new QLabel(frameBg_1);
        labelNextPiece_1->setObjectName("labelNextPiece_1");
        labelNextPiece_1->setGeometry(QRect(470, 80, 161, 171));
        labelNextPiece_1->setAlignment(Qt::AlignCenter);
        pbStart = new QPushButton(frameBg_1);
        pbStart->setObjectName("pbStart");
        pbStart->setGeometry(QRect(470, 660, 171, 91));

        retranslateUi(HigherPlay);

        QMetaObject::connectSlotsByName(HigherPlay);
    } // setupUi

    void retranslateUi(QWidget *HigherPlay)
    {
        HigherPlay->setWindowTitle(QCoreApplication::translate("HigherPlay", "Happy Player", nullptr));
        label->setText(QCoreApplication::translate("HigherPlay", "\344\270\213\344\270\200\344\270\252\346\226\271\345\235\227\357\274\232", nullptr));
        labelNextPiece_1->setText(QString());
        pbStart->setText(QCoreApplication::translate("HigherPlay", "\345\274\200 \345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HigherPlay: public Ui_HigherPlay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIGHERPLAY_H
