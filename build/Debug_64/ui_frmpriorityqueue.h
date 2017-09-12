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
    QLineEdit *txtKeyValue;
    QPushButton *cmdAddItem;
    QLabel *label;
    QTableWidget *tblHeap;
    QPushButton *cmdDelete;
    QPushButton *cmdPurgeQueue;
    QGraphicsView *canvasViewe;
    QTextEdit *txtLog;
    QPushButton *cmdClear;

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
        txtKeyValue = new QLineEdit(frmPriorityQueue);
        txtKeyValue->setObjectName(QStringLiteral("txtKeyValue"));
        txtKeyValue->setMaximumSize(QSize(150, 16777215));

        verticalLayout->addWidget(txtKeyValue);

        cmdAddItem = new QPushButton(frmPriorityQueue);
        cmdAddItem->setObjectName(QStringLiteral("cmdAddItem"));

        verticalLayout->addWidget(cmdAddItem);

        label = new QLabel(frmPriorityQueue);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        tblHeap = new QTableWidget(frmPriorityQueue);
        tblHeap->setObjectName(QStringLiteral("tblHeap"));
        tblHeap->setMinimumSize(QSize(120, 0));
        tblHeap->setMaximumSize(QSize(150, 16777215));

        verticalLayout->addWidget(tblHeap);

        cmdDelete = new QPushButton(frmPriorityQueue);
        cmdDelete->setObjectName(QStringLiteral("cmdDelete"));
        cmdDelete->setMaximumSize(QSize(150, 16777215));

        verticalLayout->addWidget(cmdDelete);

        cmdPurgeQueue = new QPushButton(frmPriorityQueue);
        cmdPurgeQueue->setObjectName(QStringLiteral("cmdPurgeQueue"));

        verticalLayout->addWidget(cmdPurgeQueue);


        horizontalLayout_2->addLayout(verticalLayout);

        canvasViewe = new QGraphicsView(frmPriorityQueue);
        canvasViewe->setObjectName(QStringLiteral("canvasViewe"));

        horizontalLayout_2->addWidget(canvasViewe);


        verticalLayout_2->addLayout(horizontalLayout_2);

        txtLog = new QTextEdit(frmPriorityQueue);
        txtLog->setObjectName(QStringLiteral("txtLog"));
        QFont font;
        font.setFamily(QStringLiteral("Courier"));
        font.setPointSize(10);
        txtLog->setFont(font);

        verticalLayout_2->addWidget(txtLog);

        cmdClear = new QPushButton(frmPriorityQueue);
        cmdClear->setObjectName(QStringLiteral("cmdClear"));

        verticalLayout_2->addWidget(cmdClear);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(frmPriorityQueue);

        cmdAddItem->setDefault(false);


        QMetaObject::connectSlotsByName(frmPriorityQueue);
    } // setupUi

    void retranslateUi(QWidget *frmPriorityQueue)
    {
        frmPriorityQueue->setWindowTitle(QApplication::translate("frmPriorityQueue", "Form", 0));
        txtKeyValue->setInputMask(QApplication::translate("frmPriorityQueue", "0000", 0));
        cmdAddItem->setText(QApplication::translate("frmPriorityQueue", "Add Value", 0));
        cmdAddItem->setShortcut(QString());
        label->setText(QApplication::translate("frmPriorityQueue", "Heap Array", 0));
        cmdDelete->setText(QApplication::translate("frmPriorityQueue", "Delte Item Selected", 0));
        cmdPurgeQueue->setText(QApplication::translate("frmPriorityQueue", "Purge Queue", 0));
        cmdClear->setText(QApplication::translate("frmPriorityQueue", "Clear Logs", 0));
    } // retranslateUi

};

namespace Ui {
    class frmPriorityQueue: public Ui_frmPriorityQueue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMPRIORITYQUEUE_H
