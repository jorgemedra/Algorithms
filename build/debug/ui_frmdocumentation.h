/********************************************************************************
** Form generated from reading UI file 'frmdocumentation.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMDOCUMENTATION_H
#define UI_FRMDOCUMENTATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmDocumentation
{
public:

    void setupUi(QWidget *frmDocumentation)
    {
        if (frmDocumentation->objectName().isEmpty())
            frmDocumentation->setObjectName(QStringLiteral("frmDocumentation"));
        frmDocumentation->resize(475, 340);

        retranslateUi(frmDocumentation);

        QMetaObject::connectSlotsByName(frmDocumentation);
    } // setupUi

    void retranslateUi(QWidget *frmDocumentation)
    {
        frmDocumentation->setWindowTitle(QApplication::translate("frmDocumentation", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class frmDocumentation: public Ui_frmDocumentation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMDOCUMENTATION_H
