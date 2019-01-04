#include "widget.h"
#include "ui_widget.h"
#include <iostream>
using namespace std;
#include<QTimer>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    i=0;
    QS_CREATE_CONNECTION(30001)

}

Widget::~Widget()
{

    delete ui;

}

void Widget::send(){

    if(i==9)
        i=0;
    else
        i++;
    QS_SET_MESSAGE.number=i;

    QS_WRITE


            QS_READ
            ui->a_in->setVisible(QS_GET_READ.z0);
            ui->b_in->setVisible(QS_GET_READ.z1);
            ui->c_in->setVisible(QS_GET_READ.z2);
            ui->d_in->setVisible(QS_GET_READ.z3);
            ui->e_in->setVisible(QS_GET_READ.z4);
            ui->f_in->setVisible(QS_GET_READ.z5);
            ui->g_in->setVisible(QS_GET_READ.z6);
}



void Widget::start(){
    ui->pushButton->setVisible(0);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(send()));//hace que se ejecute send()
    timer->start(1000);//cada 1000 milisegundos
}
