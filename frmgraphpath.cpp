
#include <iostream>
#include <sstream>
#include "frmgraphpath.h"
#include "ui_frmgraphpath.h"

using namespace std;

frmGraphPath::frmGraphPath(bool directed, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmGraphPath),
    _bDirected(directed)
{
    ui->setupUi(this);
    widget = new GraphWidget(directed);
    ui->lytHor->addWidget(widget);

    connect(widget, SIGNAL(errorRaised(int)), this, SLOT(errorRaised(int)));
    connect(widget, SIGNAL(nodeCreated(GNode*)), this, SLOT(nodeCreated(GNode*)));
    connect(widget, SIGNAL(nodesConnected(GNode*, GNode*, GEdge*)), this, SLOT(nodesConnected(GNode*, GNode*, GEdge*)));
    connect(widget, SIGNAL(nodeChanged(GNode*)), this, SLOT(nodeMoved(GNode*)));
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

void frmGraphPath::nodeCreated(GNode* node)
{

    std::stringstream data;

    std::cout <<"frmGraphPath::nodeCreated: " << node->getId() << endl;
    PathNode pnode(node->getId());
    G.push_back(pnode);
    data << node->getId();
    ui->cmbFrom->addItem(data.str().c_str());
    ui->cmbTo->addItem(data.str().c_str());
}

void frmGraphPath::nodesConnected(GNode* nodeBeg, GNode* nodeEnd, GEdge* edge)
{

    std::cout <<"frmGraphPath::nodesConnected: Nodes "
               << nodeBeg->getId() << ":" << nodeEnd->getId()
               << " with Edge " << edge->getId() << " (With Len:"<< edge->getLongitud() << ")" << endl;

    PathNode& nodeB = G[nodeBeg->getId()];
    PathNode& nodeE = G[nodeEnd->getId()];


    nodeB.addAdjacentNode(nodeE.getId(), edge->getId(),edge->getLongitud());

    if(_bDirected)
        nodeE.addAdjacentNode(nodeB.getId(), edge->getId(), edge->getLongitud(),false);
    else
        nodeE.addAdjacentNode(nodeB.getId(), edge->getId(), edge->getLongitud());
}

void frmGraphPath::nodeMoved(GNode* node)
{
//    std::cout <<"frmGraphPath::nodeMoved: Nodes "
//               << node->getId() << ":" << nodeEnd->getId()
//               << " with Edge " << edge->getId() << " (With Len:"<< edge->getLongitud() << ")" << endl;

//    node->
//    std::cout <<"frmGraphPath::nodeMoved: Node "
//               << node->getId() << endl;


}
