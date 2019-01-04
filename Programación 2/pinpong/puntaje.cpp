#include "puntaje.h"
#include "ui_puntaje.h"

Puntaje::Puntaje(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Puntaje)
{
    ui->setupUi(this);

    QPixmap pix("fondo.jpg");
    pix =pix.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette pal;
    pal.setBrush(QPalette::Background,pix);
    this->setPalette(pal);
}

Puntaje::~Puntaje()
{
    delete ui;
}
