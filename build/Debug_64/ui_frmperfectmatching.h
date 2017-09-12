/********************************************************************************
** Form generated from reading UI file 'frmperfectmatching.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMPERFECTMATCHING_H
#define UI_FRMPERFECTMATCHING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmPerfectMatching
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *txtSize;
    QPushButton *cmdBuildModel;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QTableWidget *tblManPref;
    QTableWidget *tblWomanPref;
    QVBoxLayout *lytResult;
    QPushButton *pushButton;
    QTableWidget *tblMatch;
    QTextEdit *txtLog;

    void setupUi(QWidget *frmPerfectMatching)
    {
        if (frmPerfectMatching->objectName().isEmpty())
            frmPerfectMatching->setObjectName(QStringLiteral("frmPerfectMatching"));
        frmPerfectMatching->resize(696, 535);
        frmPerfectMatching->setMinimumSize(QSize(660, 535));
        verticalLayout_2 = new QVBoxLayout(frmPerfectMatching);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        label = new QLabel(frmPerfectMatching);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        txtSize = new QLineEdit(frmPerfectMatching);
        txtSize->setObjectName(QStringLiteral("txtSize"));
        txtSize->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(txtSize);

        cmdBuildModel = new QPushButton(frmPerfectMatching);
        cmdBuildModel->setObjectName(QStringLiteral("cmdBuildModel"));

        horizontalLayout->addWidget(cmdBuildModel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tblManPref = new QTableWidget(frmPerfectMatching);
        if (tblManPref->columnCount() < 2)
            tblManPref->setColumnCount(2);
        if (tblManPref->rowCount() < 2)
            tblManPref->setRowCount(2);
        tblManPref->setObjectName(QStringLiteral("tblManPref"));
        tblManPref->setRowCount(2);
        tblManPref->setColumnCount(2);

        verticalLayout->addWidget(tblManPref);

        tblWomanPref = new QTableWidget(frmPerfectMatching);
        if (tblWomanPref->columnCount() < 2)
            tblWomanPref->setColumnCount(2);
        if (tblWomanPref->rowCount() < 2)
            tblWomanPref->setRowCount(2);
        tblWomanPref->setObjectName(QStringLiteral("tblWomanPref"));
        tblWomanPref->setRowCount(2);
        tblWomanPref->setColumnCount(2);

        verticalLayout->addWidget(tblWomanPref);


        horizontalLayout_2->addLayout(verticalLayout);

        lytResult = new QVBoxLayout();
        lytResult->setObjectName(QStringLiteral("lytResult"));
        lytResult->setSizeConstraint(QLayout::SetFixedSize);
        pushButton = new QPushButton(frmPerfectMatching);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(150, 16777215));

        lytResult->addWidget(pushButton);

        tblMatch = new QTableWidget(frmPerfectMatching);
        if (tblMatch->columnCount() < 1)
            tblMatch->setColumnCount(1);
        if (tblMatch->rowCount() < 2)
            tblMatch->setRowCount(2);
        tblMatch->setObjectName(QStringLiteral("tblMatch"));
        tblMatch->setMinimumSize(QSize(150, 0));
        tblMatch->setMaximumSize(QSize(150, 16777215));
        tblMatch->setRowCount(2);
        tblMatch->setColumnCount(1);

        lytResult->addWidget(tblMatch);


        horizontalLayout_2->addLayout(lytResult);


        verticalLayout_2->addLayout(horizontalLayout_2);

        txtLog = new QTextEdit(frmPerfectMatching);
        txtLog->setObjectName(QStringLiteral("txtLog"));
        QFont font;
        font.setFamily(QStringLiteral("Courier"));
        font.setPointSize(10);
        txtLog->setFont(font);
        txtLog->setLineWrapMode(QTextEdit::NoWrap);
        txtLog->setReadOnly(true);

        verticalLayout_2->addWidget(txtLog);


        retranslateUi(frmPerfectMatching);

        QMetaObject::connectSlotsByName(frmPerfectMatching);
    } // setupUi

    void retranslateUi(QWidget *frmPerfectMatching)
    {
        frmPerfectMatching->setWindowTitle(QApplication::translate("frmPerfectMatching", "Form", 0));
        label->setText(QApplication::translate("frmPerfectMatching", "Number of Elements By Gender:", 0));
        txtSize->setInputMask(QApplication::translate("frmPerfectMatching", "0000", 0));
        cmdBuildModel->setText(QApplication::translate("frmPerfectMatching", "Build Model", 0));
        pushButton->setText(QApplication::translate("frmPerfectMatching", "Run Algorithm", 0));
    } // retranslateUi

};

namespace Ui {
    class frmPerfectMatching: public Ui_frmPerfectMatching {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMPERFECTMATCHING_H
