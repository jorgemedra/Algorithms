#include "frmabout.h"
#include "ui_frmabout.h"
//#include <cstdio>
#include <iostream>
#include <QMdiArea>
#include <QResizeEvent>
#include <QMdiSubWindow>


using namespace std;

frmAbout::frmAbout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmAbout)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

frmAbout::~frmAbout()
{
    cout << "~frmAbout" << endl;
    delete ui;
}

void frmAbout::on_pushButton_clicked()
{
    this->close();
}

