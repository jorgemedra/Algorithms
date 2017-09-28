
#include <iostream>
#include "frmgraphs.h"
#include "ui_frmgraphs.h"
#include "gnode.h"
#include "gedge.h"


using namespace std;

frmGraphFS::frmGraphFS(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmGraphFS)
{
    ui->setupUi(this);
    widget = new GraphWidget();

    ui->lytHor->addWidget(widget);

    connect(widget, SIGNAL(errorRaised(int)), this, SLOT(errorRaised(int)));
    connect(widget, SIGNAL(nodeCreated(GNode*)), this, SLOT(nodeCreated(GNode*)));
    connect(widget, SIGNAL(nodesConnected(GNode*, GNode*, GEdge*)), this, SLOT(nodesConnected(GNode*, GNode*, GEdge*)));
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
    std::cout <<"frmGraphFS::nodeCreated: " << node->getId() << endl;
    TNode* tnode = new TNode(node->getId());
    G.push_back(tnode);

    //TODO: Write to Log.
}

void frmGraphFS::nodesConnected(GNode* nodeBeg, GNode* nodeEnd, GEdge* edge)
{
    std::cout <<"frmGraphFS::nodesConnected: Nodes "
               << nodeBeg->getId() << ":" << nodeEnd->getId()
               << " with Edge " << edge->getId()  << endl;

    TNode* nodeB = G[nodeBeg->getId()];
    TNode* nodeE = G[nodeEnd->getId()];

    nodeB->addAdjacentNode(nodeE->getId(), edge->getId()) ;
    nodeE->addAdjacentNode(nodeB->getId(), edge->getId());
}
