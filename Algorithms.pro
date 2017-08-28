#-------------------------------------------------
#
# Project created by QtCreator 2017-08-23T22:41:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Algorithms
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    frmabout.cpp \
    frmdocumentation.cpp \
    frmstablematching.cpp \
    frmpriorityqueue.cpp \
    heap.cpp

HEADERS  += mainwindow.h \
    frmabout.h \
    frmdocumentation.h \
    frmstablematching.h \
    frmpriorityqueue.h \
    heap.h

FORMS    += mainwindow.ui \
    frmabout.ui \
    frmdocumentation.ui \
    frmperfectmatching.ui \
    frmpriorityqueue.ui
