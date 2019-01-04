#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include<qs_connection.h>
#include<qs_message.h>
namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QS_CONNECTION(SendFromClient,SendFromServer)

private slots:
    void send();
    void start();

private:
    Ui::Widget *ui;
    QTimer *timer;
    int i;

};

#endif // WIDGET_H









