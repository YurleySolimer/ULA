#ifndef PUNTAJE_H
#define PUNTAJE_H

#include <QDialog>

namespace Ui {
class Puntaje;
}

class Puntaje : public QDialog
{
    Q_OBJECT
    
public:
    explicit Puntaje(QWidget *parent = 0);
    ~Puntaje();
    
private:
    Ui::Puntaje *ui;
};

#endif // PUNTAJE_H
