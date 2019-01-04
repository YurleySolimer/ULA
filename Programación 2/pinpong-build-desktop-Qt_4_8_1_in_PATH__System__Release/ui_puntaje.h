/********************************************************************************
** Form generated from reading UI file 'puntaje.ui'
**
** Created: Sat Jun 21 11:14:42 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUNTAJE_H
#define UI_PUNTAJE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_Puntaje
{
public:
    QLabel *label;
    QListWidget *listWidget;

    void setupUi(QDialog *Puntaje)
    {
        if (Puntaje->objectName().isEmpty())
            Puntaje->setObjectName(QString::fromUtf8("Puntaje"));
        Puntaje->resize(238, 320);
        label = new QLabel(Puntaje);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 201, 20));
        QPalette palette;
        QBrush brush(QColor(255, 255, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(159, 158, 158, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        label->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("gargi"));
        font.setPointSize(11);
        label->setFont(font);
        listWidget = new QListWidget(Puntaje);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 60, 211, 241));
        QPalette palette1;
        QBrush brush2(QColor(255, 85, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        listWidget->setPalette(palette1);

        retranslateUi(Puntaje);

        QMetaObject::connectSlotsByName(Puntaje);
    } // setupUi

    void retranslateUi(QDialog *Puntaje)
    {
        Puntaje->setWindowTitle(QApplication::translate("Puntaje", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Puntaje", "PUNTUACIONES MAS ALTAS", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Puntaje: public Ui_Puntaje {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUNTAJE_H
