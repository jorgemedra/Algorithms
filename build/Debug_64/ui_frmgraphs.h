/********************************************************************************
** Form generated from reading UI file 'frmgraphs.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMGRAPHS_H
#define UI_FRMGRAPHS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmGraphFS
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *lytMain;
    QHBoxLayout *lytHor;
    QVBoxLayout *LytContols;
    QLabel *lb1;
    QComboBox *cmbNodes;
    QRadioButton *optBFS;
    QRadioButton *optDFS;
    QPushButton *cmdBuildTree;
    QTextEdit *txtLogs;
    QPushButton *cmdClear;

    void setupUi(QWidget *frmGraphFS)
    {
        if (frmGraphFS->objectName().isEmpty())
            frmGraphFS->setObjectName(QStringLiteral("frmGraphFS"));
        frmGraphFS->resize(622, 480);
        verticalLayout = new QVBoxLayout(frmGraphFS);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lytMain = new QVBoxLayout();
        lytMain->setSpacing(2);
        lytMain->setObjectName(QStringLiteral("lytMain"));
        lytHor = new QHBoxLayout();
        lytHor->setSpacing(2);
        lytHor->setObjectName(QStringLiteral("lytHor"));
        LytContols = new QVBoxLayout();
        LytContols->setSpacing(2);
        LytContols->setObjectName(QStringLiteral("LytContols"));
        lb1 = new QLabel(frmGraphFS);
        lb1->setObjectName(QStringLiteral("lb1"));
        lb1->setMaximumSize(QSize(150, 20));

        LytContols->addWidget(lb1);

        cmbNodes = new QComboBox(frmGraphFS);
        cmbNodes->setObjectName(QStringLiteral("cmbNodes"));
        cmbNodes->setMaximumSize(QSize(100, 16777215));

        LytContols->addWidget(cmbNodes);

        optBFS = new QRadioButton(frmGraphFS);
        optBFS->setObjectName(QStringLiteral("optBFS"));
        optBFS->setChecked(true);

        LytContols->addWidget(optBFS);

        optDFS = new QRadioButton(frmGraphFS);
        optDFS->setObjectName(QStringLiteral("optDFS"));

        LytContols->addWidget(optDFS);

        cmdBuildTree = new QPushButton(frmGraphFS);
        cmdBuildTree->setObjectName(QStringLiteral("cmdBuildTree"));
        cmdBuildTree->setMaximumSize(QSize(100, 16777215));

        LytContols->addWidget(cmdBuildTree);


        lytHor->addLayout(LytContols);


        lytMain->addLayout(lytHor);

        txtLogs = new QTextEdit(frmGraphFS);
        txtLogs->setObjectName(QStringLiteral("txtLogs"));
        txtLogs->setMinimumSize(QSize(0, 80));
        txtLogs->setMaximumSize(QSize(16777215, 150));

        lytMain->addWidget(txtLogs);

        cmdClear = new QPushButton(frmGraphFS);
        cmdClear->setObjectName(QStringLiteral("cmdClear"));

        lytMain->addWidget(cmdClear);


        verticalLayout->addLayout(lytMain);


        retranslateUi(frmGraphFS);

        QMetaObject::connectSlotsByName(frmGraphFS);
    } // setupUi

    void retranslateUi(QWidget *frmGraphFS)
    {
        frmGraphFS->setWindowTitle(QApplication::translate("frmGraphFS", "Form", 0));
        lb1->setText(QApplication::translate("frmGraphFS", "<html><head/><body><p><span style=\" font-size:11pt;\">Select a Node as Root</span></p></body></html>", 0));
        optBFS->setText(QApplication::translate("frmGraphFS", "Use BFS", 0));
        optDFS->setText(QApplication::translate("frmGraphFS", "Use DFS", 0));
        cmdBuildTree->setText(QApplication::translate("frmGraphFS", "Build Tree", 0));
        cmdClear->setText(QApplication::translate("frmGraphFS", "Clear Logs", 0));
    } // retranslateUi

};

namespace Ui {
    class frmGraphFS: public Ui_frmGraphFS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMGRAPHS_H
