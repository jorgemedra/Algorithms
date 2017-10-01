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
    help.cpp \
    graphwidget.cpp \
    frmgraphs.cpp \
    gnode.cpp \
    gedge.cpp \
    tnode.cpp \
    afirstsearch.cpp

HEADERS  += mainwindow.h \
    frmabout.h \
    frmstablematching.h \
    frmpriorityqueue.h \
    heap.h \
    binarytreebalanced.h \
    help.h \
    graphwidget.h \
    frmgraphs.h \
    gnode.h \
    gedge.h \
    tnode.h \
    afirstsearch.h

FORMS    += mainwindow.ui \
    frmabout.ui \
    frmpriorityqueue.ui \
    frmgraphs.ui \
    frmstablematching.ui

DISTFILES += \
    Readme.md
