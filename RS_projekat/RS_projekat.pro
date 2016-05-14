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
    player.cpp \
    cell.cpp \
    board.cpp \
    game.cpp \
    energy.cpp

HEADERS  += \
    player.h \
    cell.h \
    board.h \
    game.h \
    energy.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
