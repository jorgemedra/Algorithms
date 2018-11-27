
#include <iostream>
#include "frmgraphs.h"
#include "ui_frmgraphs.h"
#include "gnode.h"
#include "gedge.h"
#include "afirstsearch.h"
#include "graphs.h"

using namespace std;
using namespace algorithms;
using namespace graphs;
using namespace graphs::ui;

frmGraphFS::frmGraphFS(bool directed, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmGraphFS),
    _bDirected(directed)
{
    ui->setupUi(this);
    widget = new GraphWidget(directed);
    ui->lytHor->addWidget(widget);

    if(_bDirected)
    {
        ui->optBFS->setText("Use BFS.");
        setWindowTitle("Directed Graphs");
    }
    else
    {
        ui->chkDAG->setVisible(false);
        setWindowTitle("Undirected Graphs");
    }

    connect(widget, SIGNAL(errorRaised(int)), this, SLOT(errorRaised(int)));
    connect(widget, SIGNAL(nodeCreated(GNode*)), this, SLOT(nodeCreated(GNode*)));
}

frmGraphFS::~frmGraphFS()
{
    delete ui;
}


/*********************
 *       SLOTS       *
 *********************/

void frmGraphFS::errorRaised(int code)
{
    std::cout <<"frmGraphFS::errorRaised: " << code << endl;
}


void frmGraphFS::nodeCreated(GNode* node)
{
    stringstream data;
    stringstream out;

    //G.addNode(node->getId());
    data << node->getId();
    ui->cmbNodes->addItem(data.str().c_str());

    cout << "Node [" << node->getId() << "] was added.";
    writeLog(out.str());
}
/*
void frmGraphFS::nodesConnected(GNode* nodeBeg, GNode* nodeEnd, GEdge* edge)
{
    stringstream out;
    cout <<"frmGraphFS::nodesConnected: Nodes "
        << nodeBeg->getId() << ":" << nodeEnd->getId()
        << " with Edge " << edge->getId() << " and logitud: " << edge->getLongitud() << endl;

    G.linkNodes(nodeBeg->getId(), nodeEnd->getId(), edge->getId(),edge->getLongitud());
}
*/

/*********************
 *      Actions      *
 *********************/

void frmGraphFS::writeLog(string log)
{
    QString data;

    data = ui->txtLogs->toPlainText();
    data += log.c_str();
    ui->txtLogs->setText(data);
}


void frmGraphFS::on_cmdClear_clicked()
{
    ui->txtLogs->clear();
}

void frmGraphFS::on_cmdBuildTree_clicked()
{
        AFirstSearch fs;
        stringstream steps;

        if(widget->Graph().empty()) return;

        Graph T{widget->Graph()}; //Clone the original Graph to get the Tree

        int root = ui->cmbNodes->currentIndex();

        if(ui->optBFS->isChecked()) fs.BFS(root,T,steps);
        else                        fs.DFS(root,T,steps);

        //ID!=-1 means that is an active Node or Edge.
        widget->resetGraphAppearance(true);

        for(long n=0; n< T.countNodes(); n++)
            widget->setItemOpacity(T[n].ID(), GITEM_NODE, T[n].isEnabled());

        for(long e=0; e < T.countEdges(); e++)
             widget->setItemOpacity(T(e).ID(), GITEM_EDGE, T(e).isEnabled());

        if(_bDirected && ui->chkDAG->isChecked()) fs.checkDAG(T,steps);

        writeLog(steps.str());

}


