#ifndef NUMBERPLAY_H
#define NUMBERPLAY_H

#include <QWidget>

namespace Ui {
class NumberPlay;
}

class NumberPlay : public QWidget
{
    Q_OBJECT

public:
    explicit NumberPlay(QWidget *parent = nullptr);
    ~NumberPlay();

private:
    Ui::NumberPlay *ui;
};

#endif // NUMBERPLAY_H
