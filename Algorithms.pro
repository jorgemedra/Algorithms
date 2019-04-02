#-------------------------------------------------
#
# Project created by QtCreator 2017-08-23T22:41:09
#
#-------------------------------------------------

#Every time that i update XCode, the next path change:
#/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk
#so, this will provoke link compilation and link problems.
#
#For this reason i stablished the ID of SDK that is used at the moment, using the macro QMAKE_MAC_SDK:
QMAKE_MAC_SDK = macosx10.14

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
    binarytreebalanced.cpp \
    help.cpp \
    graphwidget.cpp \
    frmgraphs.cpp \
    gnode.cpp \
    gedge.cpp \
    frmgraphpath.cpp \
    measuretool.cpp \
    frmsort.cpp \
    graphalgorithms.cpp \
    frmcompress.cpp \
    huffman.cpp

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
    frmgraphpath.h \
    measuretool.h \
    graphs.h \
    frmsort.h \
    sortalgorithms.h \
    graphsalgorithms.h \
    disjoint.h \
    frmcompress.h \
    huffman.h

FORMS    += mainwindow.ui \
    frmabout.ui \
    frmpriorityqueue.ui \
    frmgraphs.ui \
    frmstablematching.ui \
    frmgraphpath.ui \
    frmsorts.ui \
    frmcompress.ui

DISTFILES += \
    Readme.md
