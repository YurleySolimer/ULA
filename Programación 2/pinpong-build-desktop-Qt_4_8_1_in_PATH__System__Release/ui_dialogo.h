/********************************************************************************
** Form generated from reading UI file 'dialogo.ui'
**
** Created: Wed Jun 18 12:21:05 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGO_H
#define UI_DIALOGO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialogo
{
public:
    QLabel *barra_izquierda;
    QLabel *dona;
    QLabel *barra_derecha;
    QLabel *puntaje;
    QLineEdit *pts;

    void setupUi(QDialog *Dialogo)
    {
        if (Dialogo->objectName().isEmpty())
            Dialogo->setObjectName(QString::fromUtf8("Dialogo"));
        Dialogo->resize(714, 523);
        QFont font;
        font.setFamily(QString::fromUtf8("URW Bookman L"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        Dialogo->setFont(font);
        barra_izquierda = new QLabel(Dialogo);
        barra_izquierda->setObjectName(QString::fromUtf8("barra_izquierda"));
        barra_izquierda->setGeometry(QRect(70, 210, 19, 111));
        dona = new QLabel(Dialogo);
        dona->setObjectName(QString::fromUtf8("dona"));
        dona->setGeometry(QRect(320, 250, 61, 71));
        barra_derecha = new QLabel(Dialogo);
        barra_derecha->setObjectName(QString::fromUtf8("barra_derecha"));
        barra_derecha->setGeometry(QRect(620, 210, 19, 111));
        puntaje = new QLabel(Dialogo);
        puntaje->setObjectName(QString::fromUtf8("puntaje"));
        puntaje->setGeometry(QRect(550, 490, 91, 21));
        QPalette palette;
        QBrush brush(QColor(255, 0, 127, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(159, 158, 158, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        puntaje->setPalette(palette);
        QFont font1;
        font1.setPointSize(9);
        puntaje->setFont(font1);
        pts = new QLineEdit(Dialogo);
        pts->setObjectName(QString::fromUtf8("pts"));
        pts->setGeometry(QRect(640, 480, 41, 31));
        pts->setReadOnly(true);

        retranslateUi(Dialogo);

        QMetaObject::connectSlotsByName(Dialogo);
    } // setupUi

    void retranslateUi(QDialog *Dialogo)
    {
        Dialogo->setWindowTitle(QApplication::translate("Dialogo", "Dialog", 0, QApplication::UnicodeUTF8));
        barra_izquierda->setText(QApplication::translate("Dialogo", "TextLabel", 0, QApplication::UnicodeUTF8));
        dona->setText(QApplication::translate("Dialogo", "TextLabel", 0, QApplication::UnicodeUTF8));
        barra_derecha->setText(QApplication::translate("Dialogo", "TextLabel", 0, QApplication::UnicodeUTF8));
        puntaje->setText(QApplication::translate("Dialogo", "PUNTUACI\303\223N:", 0, QApplication::UnicodeUTF8));
        pts->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialogo: public Ui_Dialogo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGO_H
