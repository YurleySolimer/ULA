#-------------------------------------------------
#
# Project created by QtCreator 2012-03-15T16:36:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = and_ui
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h \
    qs_message.h

FORMS    += widget.ui


CONFIG += warn_off

INCLUDEPATH += . \
/home/usuarios/is/arqcomp/systemc/qsconnection

