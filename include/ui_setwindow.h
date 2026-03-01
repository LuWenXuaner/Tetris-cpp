/********************************************************************************
** Form generated from reading UI file 'setwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETWINDOW_H
#define UI_SETWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <cboard.h>

QT_BEGIN_NAMESPACE

class Ui_SetWindow
{
public:
    CBoard *frame;
    QPushButton *WayChoose;
    QCommandLinkButton *ReturnMain;

    void setupUi(QWidget *SetWindow)
    {
        if (SetWindow->objectName().isEmpty())
            SetWindow->setObjectName("SetWindow");
        SetWindow->resize(440, 395);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/Set.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        SetWindow->setWindowIcon(icon);
        SetWindow->setStyleSheet(QString::fromUtf8("*{\n"
"	font: 18pt \"\351\273\221\344\275\223\";\n"
"    color:rgb(0, 0, 0);\n"
"	border-width:10px;\n"
"	border-color:rgb(170, 0, 0);\n"
"	border-style:double;\n"
"	background-color:rgb(170, 255, 255);\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	font:16pt  \"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	font:14pt  \"Microsoft YaHei UI\";\n"
"}"));
        frame = new CBoard(SetWindow);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 441, 391));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        WayChoose = new QPushButton(frame);
        WayChoose->setObjectName("WayChoose");
        WayChoose->setGeometry(QRect(130, 150, 181, 81));
        WayChoose->setStyleSheet(QString::fromUtf8("*{\n"
"border-color:rgb(0, 85, 0);\n"
"}"));
        ReturnMain = new QCommandLinkButton(frame);
        ReturnMain->setObjectName("ReturnMain");
        ReturnMain->setGeometry(QRect(260, 330, 151, 41));
        ReturnMain->setStyleSheet(QString::fromUtf8("*\n"
"{\n"
"	border-style:none;\n"
"	font: 15pt \"\346\245\267\344\275\223\";\n"
"}"));

        retranslateUi(SetWindow);

        QMetaObject::connectSlotsByName(SetWindow);
    } // setupUi

    void retranslateUi(QWidget *SetWindow)
    {
        SetWindow->setWindowTitle(QCoreApplication::translate("SetWindow", "Form", nullptr));
        WayChoose->setText(QCoreApplication::translate("SetWindow", "\347\216\251 \346\263\225 \351\200\211 \346\213\251", nullptr));
        ReturnMain->setText(QCoreApplication::translate("SetWindow", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetWindow: public Ui_SetWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETWINDOW_H
