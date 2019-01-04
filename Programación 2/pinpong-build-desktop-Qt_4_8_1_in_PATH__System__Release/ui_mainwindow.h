/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Jun 21 10:44:14 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *JUGAR;
    QPushButton *puntaje;
    QPushButton *instrucciones;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(594, 422);
        MainWindow->setTabShape(QTabWidget::Triangular);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        JUGAR = new QPushButton(centralWidget);
        JUGAR->setObjectName(QString::fromUtf8("JUGAR"));
        JUGAR->setGeometry(QRect(220, 130, 131, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("URW Gothic L"));
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        JUGAR->setFont(font);
        JUGAR->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);\n"
"\n"
""));
        puntaje = new QPushButton(centralWidget);
        puntaje->setObjectName(QString::fromUtf8("puntaje"));
        puntaje->setGeometry(QRect(230, 250, 111, 27));
        QFont font1;
        font1.setFamily(QString::fromUtf8("URW Gothic L"));
        font1.setBold(true);
        font1.setWeight(75);
        puntaje->setFont(font1);
        puntaje->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 127);\n"
""));
        instrucciones = new QPushButton(centralWidget);
        instrucciones->setObjectName(QString::fromUtf8("instrucciones"));
        instrucciones->setGeometry(QRect(230, 210, 111, 31));
        QPalette palette;
        QBrush brush(QColor(255, 85, 127, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        instrucciones->setPalette(palette);
        QFont font2;
        font2.setFamily(QString::fromUtf8("URW Gothic L"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        instrucciones->setFont(font2);
        instrucciones->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 127);"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 594, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        JUGAR->setText(QApplication::translate("MainWindow", "JUGAR", 0, QApplication::UnicodeUTF8));
        puntaje->setText(QApplication::translate("MainWindow", "Puntuaciones", 0, QApplication::UnicodeUTF8));
        instrucciones->setText(QApplication::translate("MainWindow", "Instrucciones", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
