#include "frmdocumentation.h"
#include "ui_frmdocumentation.h"

frmDocumentation::frmDocumentation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmDocumentation)
{
    ui->setupUi(this);

}

frmDocumentation::~frmDocumentation()
{
    delete ui;
}
