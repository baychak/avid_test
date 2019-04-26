#-------------------------------------------------
#
# Project created by QtCreator 2019-04-25T12:08:22
#
#-------------------------------------------------

CONFIG += c++11

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    highlighter.cpp

HEADERS  += mainwindow.h \
    highlighter.h

FORMS    += mainwindow.ui

