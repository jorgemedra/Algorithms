/********************************************************************************
** Form generated from reading UI file 'frmpriorityqueue.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMPRIORITYQUEUE_H
#define UI_FRMPRIORITYQUEUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmPriorityQueue
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;
    QTableWidget *tableWidget;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QGraphicsView *canvasViewe;
    QTextEdit *textEdit;
    QPushButton *pushButton_3;

    void setupUi(QWidget *frmPriorityQueue)
    {
        if (frmPriorityQueue->objectName().isEmpty())
            frmPriorityQueue->setObjectName(QStringLiteral("frmPriorityQueue"));
        frmPriorityQueue->resize(430, 409);
        verticalLayout_3 = new QVBoxLayout(frmPriorityQueue);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit = new QLineEdit(frmPriorityQueue);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaximumSize(QSize(150, 16777215));

        verticalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(frmPriorityQueue);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        label = new QLabel(frmPriorityQueue);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        tableWidget = new QTableWidget(frmPriorityQueue);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(120, 0));
        tableWidget->setMaximumSize(QSize(150, 16777215));

        verticalLayout->addWidget(tableWidget);

        pushButton_4 = new QPushButton(frmPriorityQueue);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(150, 16777215));

        verticalLayout->addWidget(pushButton_4);

        pushButton_2 = new QPushButton(frmPriorityQueue);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        horizontalLayout_2->addLayout(verticalLayout);

        canvasViewe = new QGraphicsView(frmPriorityQueue);
        canvasViewe->setObjectName(QStringLiteral("canvasViewe"));

        horizontalLayout_2->addWidget(canvasViewe);


        verticalLayout_2->addLayout(horizontalLayout_2);

        textEdit = new QTextEdit(frmPriorityQueue);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout_2->addWidget(textEdit);

        pushButton_3 = new QPushButton(frmPriorityQueue);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_2->addWidget(pushButton_3);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(frmPriorityQueue);

        QMetaObject::connectSlotsByName(frmPriorityQueue);
    } // setupUi

    void retranslateUi(QWidget *frmPriorityQueue)
    {
        frmPriorityQueue->setWindowTitle(QApplication::translate("frmPriorityQueue", "Form", 0));
        lineEdit->setInputMask(QApplication::translate("frmPriorityQueue", "0000", 0));
        pushButton->setText(QApplication::translate("frmPriorityQueue", "Add Value", 0));
        label->setText(QApplication::translate("frmPriorityQueue", "Heap Array", 0));
        pushButton_4->setText(QApplication::translate("frmPriorityQueue", "Delte Item Selected", 0));
        pushButton_2->setText(QApplication::translate("frmPriorityQueue", "Purge Queue", 0));
        pushButton_3->setText(QApplication::translate("frmPriorityQueue", "Clear Logs", 0));
    } // retranslateUi

};

namespace Ui {
    class frmPriorityQueue: public Ui_frmPriorityQueue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMPRIORITYQUEUE_H
