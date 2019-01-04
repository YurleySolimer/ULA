#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPalette>
#include <QtGui>
#include "dialogo.h"
#include "instrucciones.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);
    setFocus();

    //para colocar fondo de pantalla

    QPixmap pix("FONDO.PNG");
    pix =pix.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette pal;
    pal.setBrush(QPalette::Background,pix);
    this->setPalette(pal);
    connect(ui->JUGAR,SIGNAL(clicked()),this,SLOT(jugar()));
    connect(ui->instrucciones,SIGNAL(clicked()),this,SLOT(instrucciones()));
    connect(ui->puntaje,SIGNAL(clicked()),this,SLOT(puntaje()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::jugar()
{

    this->dig.setWindowModality(Qt::ApplicationModal);
    this->dig.empezar();
    this->dig.show();
    return;

}

void MainWindow::instrucciones(){
    this->i.setWindowModality(Qt::ApplicationModal);
    this->i.show();

}

void MainWindow::puntaje(){
    this->p.setWindowModality(Qt::ApplicationModal);
    this->p.show();

}


