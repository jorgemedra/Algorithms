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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
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
    QPushButton *cmdRun;
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
        cmdRun = new QPushButton(frmGraphFS);
        cmdRun->setObjectName(QStringLiteral("cmdRun"));
        cmdRun->setMaximumSize(QSize(100, 16777215));

        LytContols->addWidget(cmdRun);


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
        cmdRun->setText(QApplication::translate("frmGraphFS", "PushButton", 0));
        cmdClear->setText(QApplication::translate("frmGraphFS", "Clear Logs", 0));
    } // retranslateUi

};

namespace Ui {
    class frmGraphFS: public Ui_frmGraphFS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMGRAPHS_H
