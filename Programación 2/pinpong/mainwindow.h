#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QKeyEvent>
#include "dialogo.h"
#include "instrucciones.h"
#include "puntaje.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    Dialogo dig;
   Instrucciones i;
   Puntaje p;


private slots:
    void jugar();
    void instrucciones();
    void puntaje();


};

#endif // MAINWINDOW_H
