#-------------------------------------------------
#
# Project created by QtCreator 2013-08-16T07:34:30
#
#-------------------------------------------------

QT       += core gui

TARGET = QtLogging
TEMPLATE = app

LIBS += -llog4cxx


SOURCES += main.cpp\
        mainwindow.cpp \
    qtappender.cpp

HEADERS  += mainwindow.h \
    qtappender.h

FORMS    += mainwindow.ui
