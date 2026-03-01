#ifndef HIGHERPLAY_H
#define HIGHERPLAY_H

#include <QWidget>

namespace Ui {
class HigherPlay;
}

class HigherPlay : public QWidget
{
    Q_OBJECT
public:
    explicit HigherPlay(QWidget *parent = nullptr);
    ~HigherPlay();

private:
    Ui::HigherPlay *ui;
};

#endif // HIGHERPLAY_H
