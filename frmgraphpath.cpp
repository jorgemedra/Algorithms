
#include <iostream>
#include <sstream>
#include "frmgraphpath.h"
#include "ui_frmgraphpath.h"

using namespace std;
using namespace graphs;
using namespace graphs::ui;

frmGraphPath::frmGraphPath(bool directed, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmGraphPath),
    _bDirected(directed)
{
    ui->setupUi(this);
    widget = new graphs::ui::GraphWidget(directed);
    ui->lytHor->addWidget(widget);

    connect(widget, SIGNAL(errorRaised(int)), this, SLOT(errorRaised(int)));
}

frmGraphPath::~frmGraphPath()
{
    delete ui;
}


/*********************
 *       SLOTS       *
 *********************/

void frmGraphPath::errorRaised(int code)
{
    std::cout <<"frmGraphPath::errorRaised: " << code << endl;
}

