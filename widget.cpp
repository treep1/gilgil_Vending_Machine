#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeMoney(0);
}

Widget::~Widget()
{
    delete ui;
}

int Widget::changeMoney(int n){
    money += n;

    ui->lcdNumber->display(QString::number(money));

    if( money < 100){
        ui->coffee->setEnabled(false);
        ui->tea->setEnabled(false);
        ui->Gongcha->setEnabled(false);
    }
    else if(money >= 100 && money < 150){
        ui->coffee->setEnabled(true);
        ui->tea->setEnabled(false);
        ui->Gongcha->setEnabled(false);
    }
    else if(money>=150 && money < 200){
        ui->coffee->setEnabled(true);
        ui->tea->setEnabled(true);
        ui->Gongcha->setEnabled(false);
    }
    else{
        ui->coffee->setEnabled(true);
        ui->tea->setEnabled(true);
        ui->Gongcha->setEnabled(true);
    }


    return money;
}

void Widget::Msg_return(){

    QMessageBox msg;
    int money10;
    int money50;
    int money100;
    int money500;
    int temp=0;
    if(money != 0){
        money500 = money / 500;
        temp = money - (500 * money500);
        money100 = temp / 100;
        temp = temp - (100 * money100);
        money50 = temp / 50;
        temp = temp - (50 * money50);
        money10 = temp / 10;
        msg.information(nullptr, "Total",QString("10won:%1 50won: %2 100won: %3 500won:%4, total : %5").arg(money10).arg(money50).arg(money100).arg(money500).arg(money));

    }
    else {
        msg.information(nullptr, "Total", QString("nothing"));
    }


}
void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_coffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_tea_clicked()
{
    changeMoney(-150);
}

void Widget::on_Gongcha_clicked()
{
    changeMoney(-200);
}

void Widget::on_change_clicked()
{
        Msg_return();
}
