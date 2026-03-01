#ifndef WAYCHOICE_H
#define WAYCHOICE_H

#include <QWidget>
#include "higherplay.h"
#include "numberplay.h"

namespace Ui {
class WayChoice;
}

class WayChoice : public QWidget
{
    Q_OBJECT

public:
    explicit WayChoice(QWidget *parent = nullptr);
    ~WayChoice();

private slots:
    void on_Way_1_clicked();

    void on_Way_2_clicked();

private:
    Ui::WayChoice *ui;
    HigherPlay *higherplay;
    NumberPlay *numberplay;
};

#endif // WAYCHOICE_H
