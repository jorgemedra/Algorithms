
#include <iostream>
#include "frmgraphs.h"
#include "ui_frmgraphs.h"
#include "gnode.h"
#include "gedge.h"
#include "afirstsearch.h"


using namespace std;
using namespace algorithms;

frmGraphFS::frmGraphFS(bool directed, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmGraphFS),
    _bDirected(directed)
{
    ui->setupUi(this);
    widget = new GraphWidget(directed);
    ui->lytHor->addWidget(widget);

    connect(widget, SIGNAL(errorRaised(int)), this, SLOT(errorRaised(int)));
    connect(widget, SIGNAL(nodeCreated(GNode*)), this, SLOT(nodeCreated(GNode*)));
    connect(widget, SIGNAL(nodesConnected(GNode*, GNode*, GEdge*)), this, SLOT(nodesConnected(GNode*, GNode*, GEdge*)));
}

frmGraphFS::~frmGraphFS()
{
    disposeGraph();
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

    std::cout <<"frmGraphFS::nodeCreated: " << node->getId() << endl;
    TNode* tnode = new TNode(node->getId());
    G.push_back(tnode);

    data << node->getId();
    ui->cmbNodes->addItem(data.str().c_str());

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

void frmGraphFS::disposeGraph()
{
    for(unsigned long i=0; i< G.size(); i++)
    {
        TNode* n = G[i];
        if(n != nullptr) delete n;
    }
}

void frmGraphFS::disposeTree()
{
    for(unsigned long i=0; i< T.size(); i++)
    {
        TNode* n = T[i];
        if(n != nullptr) delete n;
    }
}

void frmGraphFS::on_cmdClear_clicked()
{
    ui->txtLogs->clear();
}

void frmGraphFS::on_cmdBuildTree_clicked()
{
    AFirstSearch fs;
    stringstream steps;

    if(G.size() <= 0) return;

    int root = ui->cmbNodes->currentIndex();

    if(ui->optBFS->isChecked())
        fs.BFS(root,G,T,steps);
    else
        fs.DFS(root,G,T,steps);

    widget->resetGraphAppearance(true);

    for(unsigned long i=0; i< T.size(); i++)
    {
        TNode* n = nullptr;
        n = T[i];
        if(n != nullptr)
        {
           widget->setItemOpacity(n->getId(), GITEM_NODE, false);
           for(int i=0; i< n->sizeOfAdjacent(); i++)
           {
               std::pair<int,int> nad = n->getAdjacent(i);
               widget->setItemOpacity(nad.second, GITEM_EDGE, false);
           }
        }
    }

    disposeTree();
    writeLog(steps.str());
}


