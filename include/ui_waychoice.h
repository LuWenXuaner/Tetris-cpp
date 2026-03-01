/********************************************************************************
** Form generated from reading UI file 'waychoice.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAYCHOICE_H
#define UI_WAYCHOICE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WayChoice
{
public:
    QFrame *frame;
    QPushButton *Way_1;
    QPushButton *Way_2;

    void setupUi(QWidget *WayChoice)
    {
        if (WayChoice->objectName().isEmpty())
            WayChoice->setObjectName("WayChoice");
        WayChoice->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/way.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        WayChoice->setWindowIcon(icon);
        frame = new QFrame(WayChoice);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 401, 301));
        frame->setStyleSheet(QString::fromUtf8("*\n"
"{\n"
"	\n"
"	background-color: rgb(85, 170, 255);\n"
"	font: 18pt \"\351\273\221\344\275\223\";\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	font:22pt  \"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	font:20pt  \"Microsoft YaHei UI\";\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Way_1 = new QPushButton(frame);
        Way_1->setObjectName("Way_1");
        Way_1->setGeometry(QRect(30, 110, 151, 101));
        Way_2 = new QPushButton(frame);
        Way_2->setObjectName("Way_2");
        Way_2->setGeometry(QRect(220, 110, 151, 101));

        retranslateUi(WayChoice);

        QMetaObject::connectSlotsByName(WayChoice);
    } // setupUi

    void retranslateUi(QWidget *WayChoice)
    {
        WayChoice->setWindowTitle(QCoreApplication::translate("WayChoice", "Way", nullptr));
        Way_1->setText(QCoreApplication::translate("WayChoice", "\350\277\233\351\230\266\345\235\227\346\250\241\345\274\217", nullptr));
        Way_2->setText(QCoreApplication::translate("WayChoice", "\346\225\260\345\255\227\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WayChoice: public Ui_WayChoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAYCHOICE_H
