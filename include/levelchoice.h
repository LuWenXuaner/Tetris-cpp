#ifndef LEVELCHOICE_H
#define LEVELCHOICE_H

#include <QWidget>

namespace Ui {
class LevelChoice;
}

class LevelChoice : public QWidget
{
    Q_OBJECT

public:
    explicit LevelChoice(QWidget *parent = nullptr);
    ~LevelChoice();

private:
    Ui::LevelChoice *ui;

private slots:
    void ReturnSetting();

signals:
    void ReturnSignal();

};

#endif // LEVELCHOICE_H
