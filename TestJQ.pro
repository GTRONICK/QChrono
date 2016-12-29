#-------------------------------------------------
#
# Project created by QtCreator 2016-07-26T14:53:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QChrono
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    worker.cpp \
    styles.cpp

HEADERS  += mainwindow.h \
    worker.h \
    styles.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc \
    fonts.qrc
