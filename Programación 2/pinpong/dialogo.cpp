#include "dialogo.h"
#include "ui_dialogo.h"
#include <QPixmap>
#include <QPalette>
#include <QtGui>
#include <QTime>
#include <string>

Dialogo::Dialogo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogo)

{
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);


    QPixmap pix("fondo.jpg");
    pix =pix.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette pal;
    pal.setBrush(QPalette::Background,pix);
    this->setPalette(pal);

    QPixmap pix_barra_izquierda("barra.jpg");
    pix_barra_izquierda =pix_barra_izquierda.scaled(ui->barra_izquierda->size(),Qt::IgnoreAspectRatio);
    ui->barra_izquierda->setPixmap(pix_barra_izquierda);

    QPixmap pix_barra_derecha("barra.jpg");
    pix_barra_derecha =pix_barra_derecha.scaled(ui->barra_derecha->size(),Qt::IgnoreAspectRatio);
    ui->barra_derecha->setPixmap(pix_barra_derecha);

    QPixmap pix_dona("dona.png");
    pix_dona =pix_dona.scaled(ui->dona->size(),Qt::IgnoreAspectRatio);
    ui->dona->setPixmap(pix_dona);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(mover_dona()));
    connect(timer,SIGNAL(timeout()),this,SLOT(mover_barra2()));



    x =1;
    y =1;
    vel_x =1;
    vel_y =1;
    puntos=0;
    ui->pts->setText(QString::number(0));
    i=8;


}

Dialogo::~Dialogo()
{
    delete ui;
}

void Dialogo::empezar(){
  timer->start(i);
 }

void Dialogo:: mover_dona(){


    if (ui->dona->geometry().y()+ui->dona->geometry().height() >= this->size().height()-ui->pts->geometry().height()) {
        y =-1;}

    if (ui->dona->geometry().y() <= 0){
        y =1;}


    if ((ui->dona->geometry().x()+ui->dona->geometry().width() >= ui->barra_derecha->geometry().x())
         && (ui->dona->geometry().y() < ui->barra_derecha->geometry().y()+ui->barra_derecha->geometry().height())
         && (ui->dona->geometry().y()+ui->dona->geometry().height() > ui->barra_derecha->geometry().y())
            && (ui->dona->geometry().height()/2==ui->barra_derecha->geometry().height()/2)   ){
            x =-1;
            y=0;

    }


    if ((ui->dona->geometry().x()+ui->dona->geometry().width() >= ui->barra_derecha->geometry().x())
         && (ui->dona->geometry().y() < ui->barra_derecha->geometry().y()+ui->barra_derecha->geometry().height())
         && (ui->dona->geometry().y()+ui->dona->geometry().height() > ui->barra_derecha->geometry().y())){
            x =-1;

    }

    if ((ui->dona->geometry().x() <= ui->barra_izquierda->geometry().x()+ui->barra_izquierda->geometry().width())
         && (ui->dona->geometry().y() < ui->barra_izquierda->geometry().y()+ui->barra_izquierda->geometry().height())
         && (ui->dona->geometry().y()+ui->dona->geometry().height() > ui->barra_izquierda->geometry().y()))

    {
        x =1;
        if (ui->dona->geometry().height()/2>=ui->barra_derecha->geometry().height()/2) {y=0;}
        puntos=ui->pts->text().toInt();
        ui->pts->setText(QString::number(puntos+10));

        }


    if(ui->dona->geometry().x() <0) {

        ganar(0);

    }


    ui->dona->setGeometry(ui->dona->geometry().x()+x*vel_x,\
                          ui->dona->geometry().y()+y*vel_y,\
                          ui->dona->geometry().width(),\
                          ui->dona->geometry().height());
}

void Dialogo:: mover_barra2(){

    if (ui->barra_derecha->geometry().y()+ui->barra_derecha->geometry().height() >=
            this->size().height()-ui->pts->geometry().height())
        y =-1;
    if (ui->barra_derecha->geometry().y() <= 0)
        y =1;


    ui->barra_derecha->setGeometry(ui->barra_derecha->geometry().x()+x*0,\
                           ui->barra_derecha->geometry().y()+y*1,\
                           ui->barra_derecha->geometry().width(),\
                           ui->barra_derecha->geometry().height());
}

void Dialogo:: mover_barra1(int x, int y) {


    if (ui->barra_izquierda->geometry().y()+ui->barra_izquierda->geometry().height() >= this->size().height())
        y =-1;
    if (ui->barra_izquierda->geometry().y() <= 0)
        y =1;

    ui->barra_izquierda->setGeometry(ui->barra_izquierda->geometry().x()+x*0,\
                           ui->barra_izquierda->geometry().y()+y*1,\
                           ui->barra_izquierda->geometry().width(),\
                           ui->barra_izquierda->geometry().height());
}

void Dialogo::keyPressEvent(QKeyEvent *event){

    switch (event->key()) {
    case Qt::Key_W:
        moverArriba();
        break;
    case Qt::Key_S:
        moverAbajo();
        break;
    default:
        break;
    }
}


void Dialogo::moverAbajo() {
    mover_barra1(0, STEP);
}

void Dialogo::moverArriba() {
    mover_barra1(0, -STEP);
}

void Dialogo::velocidad(int n){

    }


void Dialogo::ganar(int n) {

      if(n==1) {

        vel_x*=-1;
        vel_y*=-1;

    }

    else {

      timer->stop();
      QMessageBox box;
      box.setText(("FIN DEL JUEGO"));
      box.setInformativeText(QString::number(puntos+10));
      box.exec();
      ui->dona->setGeometry(width()/2, height()/2, ui->dona->width(), ui->dona->height());
      ui->barra_derecha->setGeometry(ui->barra_derecha->x(), height()/2, ui->barra_derecha->width(),\
                                     ui->barra_derecha->height());

      close();
      puntos=0;
      ui->pts->setText(QString::number(puntos));

    }


}





