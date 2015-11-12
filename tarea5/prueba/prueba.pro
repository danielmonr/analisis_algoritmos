#-------------------------------------------------
#
# Project created by QtCreator 2015-11-10T13:51:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = prueba
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    canvas.cpp \
    window.cpp

HEADERS  += mainwindow.h \
    canvas.h \
    window.h

FORMS    += mainwindow.ui \
    canvas.ui \
    window.ui
