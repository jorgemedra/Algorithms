/********************************************************************************
** Form generated from reading UI file 'frmabout.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMABOUT_H
#define UI_FRMABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmAbout
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *frmAbout)
    {
        if (frmAbout->objectName().isEmpty())
            frmAbout->setObjectName(QStringLiteral("frmAbout"));
        frmAbout->resize(360, 160);
        frmAbout->setMinimumSize(QSize(360, 160));
        frmAbout->setMaximumSize(QSize(360, 160));
        frmAbout->setBaseSize(QSize(360, 160));
        label = new QLabel(frmAbout);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 311, 51));
        label->setTextFormat(Qt::RichText);
        pushButton = new QPushButton(frmAbout);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 120, 113, 32));

        retranslateUi(frmAbout);

        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(frmAbout);
    } // setupUi

    void retranslateUi(QWidget *frmAbout)
    {
        frmAbout->setWindowTitle(QApplication::translate("frmAbout", "About", 0));
        label->setText(QApplication::translate("frmAbout", "<html><head/><body><p><span style=\" font-size:36pt; color:#1747c9;\">Algorithm Samples</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("frmAbout", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class frmAbout: public Ui_frmAbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMABOUT_H
