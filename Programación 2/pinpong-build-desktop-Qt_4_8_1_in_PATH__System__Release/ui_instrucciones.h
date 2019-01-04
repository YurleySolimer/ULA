/********************************************************************************
** Form generated from reading UI file 'instrucciones.ui'
**
** Created: Wed Jun 18 23:28:13 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUCCIONES_H
#define UI_INSTRUCCIONES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Instrucciones
{
public:
    QPushButton *Volver;
    QLabel *ins;
    QLabel *ins_2;
    QLabel *ins_3;

    void setupUi(QDialog *Instrucciones)
    {
        if (Instrucciones->objectName().isEmpty())
            Instrucciones->setObjectName(QString::fromUtf8("Instrucciones"));
        Instrucciones->setEnabled(true);
        Instrucciones->resize(310, 224);
        Volver = new QPushButton(Instrucciones);
        Volver->setObjectName(QString::fromUtf8("Volver"));
        Volver->setGeometry(QRect(230, 10, 61, 20));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(159, 158, 158, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        Volver->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("URW Gothic L"));
        font.setPointSize(10);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        Volver->setFont(font);
        Volver->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);\n"
"\n"
""));
        ins = new QLabel(Instrucciones);
        ins->setObjectName(QString::fromUtf8("ins"));
        ins->setGeometry(QRect(20, 60, 271, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        ins->setPalette(palette1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("gargi"));
        font1.setPointSize(12);
        ins->setFont(font1);
        ins_2 = new QLabel(Instrucciones);
        ins_2->setObjectName(QString::fromUtf8("ins_2"));
        ins_2->setGeometry(QRect(10, 100, 291, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        ins_2->setPalette(palette2);
        ins_2->setFont(font1);
        ins_3 = new QLabel(Instrucciones);
        ins_3->setObjectName(QString::fromUtf8("ins_3"));
        ins_3->setGeometry(QRect(10, 140, 281, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        ins_3->setPalette(palette3);
        ins_3->setFont(font1);

        retranslateUi(Instrucciones);

        QMetaObject::connectSlotsByName(Instrucciones);
    } // setupUi

    void retranslateUi(QDialog *Instrucciones)
    {
        Instrucciones->setWindowTitle(QApplication::translate("Instrucciones", "Dialog", 0, QApplication::UnicodeUTF8));
        Volver->setText(QApplication::translate("Instrucciones", "Volver", 0, QApplication::UnicodeUTF8));
        ins->setText(QApplication::translate("Instrucciones", "Presione la tecla W para mover la dona", 0, QApplication::UnicodeUTF8));
        ins_2->setText(QApplication::translate("Instrucciones", "dona hacia arriba o la tecla S para ", 0, QApplication::UnicodeUTF8));
        ins_3->setText(QApplication::translate("Instrucciones", "moverla hacia abajo respectivamente", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Instrucciones: public Ui_Instrucciones {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCCIONES_H
