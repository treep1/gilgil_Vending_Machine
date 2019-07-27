#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    int money = 0;
    int changeMoney(int n);
    void Msg_return();
private slots:

    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_coffee_clicked();

    void on_tea_clicked();

    void on_Gongcha_clicked();

    void on_change_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
