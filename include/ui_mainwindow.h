/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <cboard.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *frameBg;
    QGridLayout *gridLayout;
    QLCDNumber *lcdTime;
    QLCDNumber *lcdRemoved;
    QPushButton *pbExit;
    QLabel *label_2;
    CBoard *frameTetrisBoard;
    QLabel *Contents;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *labelNextPiece;
    QPushButton *pbStart;
    QLCDNumber *lcdScore;
    QPushButton *pbPause;
    QLCDNumber *lcdLevel;
    QLabel *label_4;
    QLabel *label;
    QPushButton *pbSet;
    QPushButton *level;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(652, 577);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/tetrisIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("*{\n"
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
"QFrame#frameBg{\n"
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
"	border-image: url(:/image/NWAFU_bg.png);\n"
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
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        frameBg = new QFrame(centralwidget);
        frameBg->setObjectName("frameBg");
        frameBg->setFrameShape(QFrame::StyledPanel);
        frameBg->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frameBg);
        gridLayout->setObjectName("gridLayout");
        lcdTime = new QLCDNumber(frameBg);
        lcdTime->setObjectName("lcdTime");

        gridLayout->addWidget(lcdTime, 1, 2, 1, 1);

        lcdRemoved = new QLCDNumber(frameBg);
        lcdRemoved->setObjectName("lcdRemoved");

        gridLayout->addWidget(lcdRemoved, 8, 2, 1, 1);

        pbExit = new QPushButton(frameBg);
        pbExit->setObjectName("pbExit");

        gridLayout->addWidget(pbExit, 11, 0, 1, 1);

        label_2 = new QLabel(frameBg);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label_2, 2, 2, 1, 1);

        frameTetrisBoard = new CBoard(frameBg);
        frameTetrisBoard->setObjectName("frameTetrisBoard");
        frameTetrisBoard->setMinimumSize(QSize(300, 58));
        frameTetrisBoard->setAutoFillBackground(false);
        frameTetrisBoard->setFrameShape(QFrame::StyledPanel);
        frameTetrisBoard->setFrameShadow(QFrame::Raised);
        Contents = new QLabel(frameTetrisBoard);
        Contents->setObjectName("Contents");
        Contents->setGeometry(QRect(90, 220, 141, 50));
        Contents->setStyleSheet(QString::fromUtf8("*\n"
"{\n"
"  color:rgb(170, 0, 0);\n"
"}"));
        Contents->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(frameTetrisBoard, 0, 1, 12, 1);

        label_3 = new QLabel(frameBg);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label_3, 5, 2, 1, 1);

        label_5 = new QLabel(frameBg);
        label_5->setObjectName("label_5");
        label_5->setScaledContents(true);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        labelNextPiece = new QLabel(frameBg);
        labelNextPiece->setObjectName("labelNextPiece");
        labelNextPiece->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelNextPiece, 1, 0, 2, 1);

        pbStart = new QPushButton(frameBg);
        pbStart->setObjectName("pbStart");

        gridLayout->addWidget(pbStart, 7, 0, 1, 1);

        lcdScore = new QLCDNumber(frameBg);
        lcdScore->setObjectName("lcdScore");
        lcdScore->setAutoFillBackground(false);

        gridLayout->addWidget(lcdScore, 3, 2, 1, 1);

        pbPause = new QPushButton(frameBg);
        pbPause->setObjectName("pbPause");

        gridLayout->addWidget(pbPause, 8, 0, 1, 1);

        lcdLevel = new QLCDNumber(frameBg);
        lcdLevel->setObjectName("lcdLevel");

        gridLayout->addWidget(lcdLevel, 6, 2, 1, 1);

        label_4 = new QLabel(frameBg);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label_4, 7, 2, 1, 1);

        label = new QLabel(frameBg);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pbSet = new QPushButton(frameBg);
        pbSet->setObjectName("pbSet");

        gridLayout->addWidget(pbSet, 5, 0, 1, 1);

        level = new QPushButton(frameBg);
        level->setObjectName("level");

        gridLayout->addWidget(level, 6, 0, 1, 1);


        verticalLayout->addWidget(frameBg);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(pbExit, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\344\277\204\347\275\227\346\226\257\346\226\271\345\235\227", nullptr));
        pbExit->setText(QCoreApplication::translate("MainWindow", "\351\200\200 \345\207\272", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\210\206 \346\225\260", nullptr));
        Contents->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "\351\200\237 \345\272\246", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\255\230\346\264\273\346\227\266\351\227\264", nullptr));
        labelNextPiece->setText(QString());
        pbStart->setText(QCoreApplication::translate("MainWindow", "\345\274\200 \345\247\213", nullptr));
        pbPause->setText(QCoreApplication::translate("MainWindow", "\346\232\202 \345\201\234", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\266\210\351\231\244\350\241\214\346\225\260", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\344\270\252", nullptr));
        pbSet->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        level->setText(QCoreApplication::translate("MainWindow", "\345\233\260 \351\232\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
