#-------------------------------------------------
#
# Project created by QtCreator 2016-04-24T12:34:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RS_projekat
TEMPLATE = app


SOURCES += main.cpp\
    path.cpp \
    player.cpp \
    wall.cpp \
    cell.cpp \
    board.cpp

HEADERS  += \
    path.h \
    player.h \
    wall.h \
    cell.h \
    board.h

FORMS    += mainwindow.ui
