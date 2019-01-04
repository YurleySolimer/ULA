#include "instrucciones.h"
#include "ui_instrucciones.h"
#include <QPixmap>
#include <QPalette>
#include <QtGui>

Instrucciones::Instrucciones(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Instrucciones)
{
    ui->setupUi(this);

    QPixmap pix("fondo.jpg");
    pix =pix.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette pal;
    pal.setBrush(QPalette::Background,pix);
    this->setPalette(pal);



    connect(ui->Volver,SIGNAL(clicked()),this,SLOT(volver()));



}

Instrucciones::~Instrucciones()
{
    delete ui;
}

void Instrucciones::volver(){

    close();


}
