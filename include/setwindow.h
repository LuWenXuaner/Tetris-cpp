#ifndef SETWINDOW_H
#define SETWINDOW_H

#include <QWidget>
#include "waychoice.h"

namespace Ui {
class SetWindow;
}

class SetWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SetWindow(QWidget *parent = nullptr);
    ~SetWindow();

private slots:
    void on_ReturnMain_clicked();
    void ShowSetting();
    void on_WayChoose_clicked();

private:
    Ui::SetWindow *ui;
    bool signal = false;
    WayChoice *waychoice;

signals:
    void Return_signal();
};

#endif // SETWINDOW_H
