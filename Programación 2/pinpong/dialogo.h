#ifndef DIALOGO_H
#define DIALOGO_H

#include <QDialog>
#define STEP 8
namespace Ui {
class Dialogo;
}

class Dialogo : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialogo(QWidget *parent = 0);
    ~Dialogo();
    int x;
    int y;
    int vel_x;
    int vel_y;
    int puntos;
    int i;


    
private:
    Ui::Dialogo *ui;
    void keyPressEvent(QKeyEvent * key);
    QTimer *timer;

public slots:
    void empezar();
    void mover_dona();
    void mover_barra2();
    void mover_barra1(int x, int y);
    void moverArriba();
    void moverAbajo();
    void velocidad(int n);
    void ganar(int n);



};

#endif // DIALOGO_H
