
#include <iostream>
#include <sstream>
#include <unordered_map>
#include "frmgraphpath.h"
#include "ui_frmgraphpath.h"
#include "graphs.h"
#include "graphsalgorithms.h"

using namespace std;
using namespace algorithms;
using namespace graphs;
using namespace graphs::ui;


frmGraphPath::frmGraphPath(bool directed, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmGraphPath),
    _bDirected(directed)
{
    ui->setupUi(this);
    widget = new graphs::ui::GraphWidget(directed);
    widget->showArrowLabel();
    ui->lytHor->addWidget(widget);

    ui->optDjskt->setChecked(true);

    connect(widget, SIGNAL(errorRaised(int)), this, SLOT(errorRaised(int)));
    connect(widget, SIGNAL(nodeCreated(GNode*)), this, SLOT(nodeCreated(GNode*)));
}

frmGraphPath::~frmGraphPath()
{
    delete ui;
}

void frmGraphPath::writeLog(string log)
{
    QString data;

    data = ui->txtLogs->toPlainText();
    data += log.c_str();
    ui->txtLogs->setText(data);
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
    stringstream data;
    stringstream dataSize;
    stringstream out;

    //G.addNode(node->getId());
    data << node->getId();
    dataSize << node->getId() +1;

    ui->cmbFrom->addItem(data.str().c_str());
    ui->cmbTo->addItem(data.str().c_str());
    ui->cmbSize->addItem(dataSize.str().c_str());

    cout << "Node [" << node->getId() << "] was added.";
    writeLog(out.str());
}

/*********************
 *       FORM        *
 *********************/

void frmGraphPath::on_cmdFind_clicked()
{
    long from = ui->cmbFrom->currentIndex();

    if(ui->optDjskt->isChecked())
    {
        long to = ui->cmbTo->currentIndex();
        procDijkstra(from,to);
    }
    else if(ui->optPrim->isChecked())
        procPRIM(from);
    else if(ui->optKruskal->isChecked())
        procKruskatCluster();
    else if(ui->optCluster->isChecked())
    {
        long size = ui->cmbSize->currentIndex() +1;
        procKruskatCluster(size, true);
    }
}

void frmGraphPath::selectOption()
{
    ui->cmbFrom->setEnabled( ui->optKruskal->isChecked() ? false : true);
    ui->cmbTo->setEnabled( ui->optDjskt->isChecked() ? true : false );
    ui->cmbSize->setEnabled(ui->optCluster->isChecked());

}

void frmGraphPath::on_cmdClear_clicked()
{
    ui->txtLogs->clear();
}

void frmGraphPath::on_optDjskt_clicked()
{
    selectOption();
}

void frmGraphPath::on_optPrim_clicked()
{
    selectOption();
}

void frmGraphPath::on_optKruskal_clicked()
{
    selectOption();
}

void frmGraphPath::on_optCluster_clicked()
{
    selectOption();
}

/*********************
 *   PROC RESULTS    *
 *********************/

void frmGraphPath::procDijkstra(long from, long to)
{
    stringstream steps;

    if(widget->Graph().empty()) return;

    Graph G{widget->Graph()}; //Clone the original Graph

    stack<tuple<long,long,long >> path = shortpath::dijkstra(from,to,G,steps);

    widget->resetGraphAppearance(false);

    steps << "::Shorter Path: ";
    bool started = true;
    while(!path.empty())
    {
        tuple<long,long,long > pthStep = path.top();
        path.pop();

        long idNode = std::get<0>(pthStep);
        long idEdge = std::get<1>(pthStep);
        long cost = std::get<2>(pthStep);

        if(started) started = false;
        else steps << " : ";

        steps << "N[" << idNode << "]-E[" << idEdge << "]-C[" << cost << "]";


        widget->setItemOpacity(idNode, GITEM_NODE, true);

        if(idEdge > -1)
            widget->setItemOpacity(idEdge, GITEM_EDGE,true);
    }

    steps << " (END) " << endl;
    writeLog(steps.str());
}

void frmGraphPath::procPRIM(long from)
{
    stringstream steps;

    if(widget->Graph().empty()) return;

    Graph G{widget->Graph()}; //Clone the original Graph

    minimun_spanning::prim(from,G,steps);

    widget->resetGraphAppearance(false);

    //redraw the Tree, the new graph.
    for(int n=0; n < G.countNodes(); n++)
        widget->setItemOpacity(n, GITEM_NODE, G[n].isEnabled());

    for(int e=0; e < G.countEdges(); e++)
        widget->setItemOpacity(e, GITEM_EDGE, G(e).isEnabled());

    steps << " (END) " << endl;
    writeLog(steps.str());
}

void frmGraphPath::procKruskatCluster(long size, bool isCluster)
{
    stringstream steps;

    if(widget->Graph().empty()) return;

    Graph G{widget->Graph()}; //Clone the original Graph

    if(!isCluster)
        minimun_spanning::kruskal(G,steps);
    else
        minimun_spanning::findClusters(size,G,steps);

    widget->resetGraphAppearance(false);

    //redraw the Tree, the new graph.
    for(int n=0; n < G.countNodes(); n++)
        widget->setItemOpacity(n, GITEM_NODE, G[n].isEnabled());

    for(int e=0; e < G.countEdges(); e++)
        widget->setItemOpacity(e, GITEM_EDGE, G(e).isEnabled());

    writeLog(steps.str());
}
