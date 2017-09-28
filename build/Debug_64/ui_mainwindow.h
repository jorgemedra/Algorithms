/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMain_Documentation;
    QAction *actionAbout;
    QAction *actionLogs;
    QAction *actionStable_Matching;
    QAction *actionPriority_Queue;
    QAction *actionBSD;
    QWidget *centralWidget;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menuAlgorithms;
    QMenu *menuSystem;
    QMenu *menuBasic;
    QMenu *menuGraphs;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(586, 422);
        actionMain_Documentation = new QAction(MainWindow);
        actionMain_Documentation->setObjectName(QStringLiteral("actionMain_Documentation"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionLogs = new QAction(MainWindow);
        actionLogs->setObjectName(QStringLiteral("actionLogs"));
        actionStable_Matching = new QAction(MainWindow);
        actionStable_Matching->setObjectName(QStringLiteral("actionStable_Matching"));
        actionPriority_Queue = new QAction(MainWindow);
        actionPriority_Queue->setObjectName(QStringLiteral("actionPriority_Queue"));
        actionBSD = new QAction(MainWindow);
        actionBSD->setObjectName(QStringLiteral("actionBSD"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setGeometry(QRect(10, 10, 271, 171));
        mdiArea->setAutoFillBackground(false);
        mdiArea->setFrameShape(QFrame::Panel);
        mdiArea->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 586, 22));
        menuBar->setNativeMenuBar(true);
        menuAlgorithms = new QMenu(menuBar);
        menuAlgorithms->setObjectName(QStringLiteral("menuAlgorithms"));
        menuSystem = new QMenu(menuBar);
        menuSystem->setObjectName(QStringLiteral("menuSystem"));
        menuBasic = new QMenu(menuSystem);
        menuBasic->setObjectName(QStringLiteral("menuBasic"));
        menuGraphs = new QMenu(menuSystem);
        menuGraphs->setObjectName(QStringLiteral("menuGraphs"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuAlgorithms->menuAction());
        menuBar->addAction(menuSystem->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuAlgorithms->addAction(actionLogs);
        menuSystem->addAction(menuBasic->menuAction());
        menuSystem->addAction(menuGraphs->menuAction());
        menuBasic->addAction(actionStable_Matching);
        menuBasic->addAction(actionPriority_Queue);
        menuGraphs->addAction(actionBSD);
        menuHelp->addAction(actionMain_Documentation);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Algorithms", 0));
        actionMain_Documentation->setText(QApplication::translate("MainWindow", "Main Documentation", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionAbout->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionLogs->setText(QApplication::translate("MainWindow", "Logs", 0));
        actionStable_Matching->setText(QApplication::translate("MainWindow", "Stable Matching", 0));
        actionPriority_Queue->setText(QApplication::translate("MainWindow", "Priority Queue", 0));
        actionBSD->setText(QApplication::translate("MainWindow", "BFS/DFS", 0));
        menuAlgorithms->setTitle(QApplication::translate("MainWindow", "System", 0));
        menuSystem->setTitle(QApplication::translate("MainWindow", "Algorithm", 0));
        menuBasic->setTitle(QApplication::translate("MainWindow", "Basic", 0));
        menuGraphs->setTitle(QApplication::translate("MainWindow", "Graphs", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
