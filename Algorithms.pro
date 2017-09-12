#-------------------------------------------------
#
# Project created by QtCreator 2017-08-23T22:41:09
#
#-------------------------------------------------

QT       += core gui
QT       += webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Algorithms
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    frmabout.cpp \
    frmstablematching.cpp \
    frmpriorityqueue.cpp \
    heap.cpp \
    binarytreebalanced.cpp \
    help.cpp

HEADERS  += mainwindow.h \
    frmabout.h \
    frmstablematching.h \
    frmpriorityqueue.h \
    heap.h \
    binarytreebalanced.h \
    help.h

FORMS    += mainwindow.ui \
    frmabout.ui \
    frmperfectmatching.ui \
    frmpriorityqueue.ui

DISTFILES += \
    Readme.md
