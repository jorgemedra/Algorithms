#include "graphwidget.h"
#include <QGraphicsOpacityEffect>
#include <QMouseEvent>
#include <QObject>

#include<cstdlib>
#include<iostream>
#include<sstream>

using namespace std;
using namespace graphs;
using namespace graphs::ui;

GraphWidget::GraphWidget(bool directed, QWidget *parent)
    : QGraphicsView(parent),      
      _NodeIndex(-1),
      _EdgeIndex(-1),      
      bShift(false),
      _bDirected(directed),      
      _bArrowLabel{false},
      _countSel(0),
      G{}
{    
    scene =  new QGraphicsScene(this);
    setScene(scene);
    scene->addEllipse(0,0,2,2);
    scene->addEllipse(-100,  100 ,1,1);
    scene->addEllipse(-100, -100,1,1);
    scene->addEllipse(100, 100,1,1);
    scene->addEllipse(100, -100,1,1);

    nSelected[0]=-1;
    nSelected[1]=-1;
}

void GraphWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    qreal x,y;

    QPointF point = mapToScene(event->x(),event->y());
    x = point.x();
    y = point.y();

    if(_NodeIndex >= MAX_GNODES)
    {
        errorRaised(ERROR::MAX_NODES_REACHED);
        return;
    }

    _NodeIndex = G.createNode(); //Since V2.0 Create the new Vertex in the graph

    GNode* node = new GNode();
    scene->addItem(node);

    node->setPos(x - (GNODE_WIDTH/2), y - (GNODE_WIDTH/2));
    node->setId(_NodeIndex);
    _Nodes[_NodeIndex] = node;

    connect(node, SIGNAL(pressed(GNode*)), this, SLOT(nodePressed(GNode*)));
    //connect(node, SIGNAL(moved(GNode*)), this, SLOT(nodeMoved(GNode*)));

   emit nodeCreated(node);

}

void GraphWidget::keyPressEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_Shift)
        bShift = true;
}

void GraphWidget::keyReleaseEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_Shift)
    {
        bShift = false;
        resetNodes();
    }
}

void GraphWidget::nodePressed(GNode* node)
{
    if(bShift)
    {
        //cout << "nodePressed: " << node->getId() << endl;

        if(nSelected[0] == node->getId()) //Was Selected
        {
            node->setSelected(false);
            nSelected[0] = nSelected[1];
            nSelected[1] = -1;
            _countSel--;
            cout << "Node [0]:(" << node->getId() << ") Deselected, shift Node[1] to Node[0]" << endl;
        }
        else if(nSelected[1]== node->getId()) //Was Selected
        {
            node->setSelected(false);
            nSelected[1] = -1;
            _countSel--;
            cout << "Node [1]:(" << node->getId() << ") Deselected." << endl;
        }
        else
        {
            if(_countSel < 2)
            {
                nSelected[_countSel] = node->getId();
                cout << "Node [" << _countSel << "]:(" << node->getId() << ") Selected." << endl;
                _countSel++;
                node->setSelected(true);
            }

            if(_countSel == 2)
                connectNodes();
        }
    }
}

//void GraphWidget::nodeMoved(GNode* node)
//{
//    //emit nodeChanged(node);
//}

void GraphWidget::edgeLengthChanged(int id, long newL)
{
    G.updateEdgeLength(id,newL);
}

void GraphWidget::resetNodes()
{
    for(int i=0; i <= _NodeIndex; i++)
        _Nodes[i]->setSelected(false);

    nSelected[0]=-1;
    nSelected[1]=-1;

    _countSel = 0;
}

void GraphWidget::connectNodes()
{

    GNode* beg = _Nodes[nSelected[0]];
    GNode* end = _Nodes[nSelected[1]];

    if(beg->isAdjacentNode(end))
    {
        //TODO: Send an error
        resetNodes();
        return;
    }

    GEdge* edge = new GEdge();
    edge->showArrow(_bArrowLabel);
    scene->addItem(edge);

    QLineF line;
    line.setLine(beg->pos().x() + (GNODE_WIDTH/2), beg->pos().y() + (GNODE_WIDTH/2),
                 end->pos().x() + (GNODE_WIDTH/2), end->pos().y() + (GNODE_WIDTH/2));

    //_EdgeIndex++;
    _EdgeIndex = G.connectNodes(beg->getId(),end->getId(),edge->getLongitud(),_bDirected);

    edge->setId(_EdgeIndex);
    edge->setLine(line);
    edge->setZValue(-1);
    edge->showArrow(_bDirected);

    beg->setAdjacentNode(end);
    beg->setEdge(edge);
    end->setAdjacentNode(beg);
    end->setEdge(edge);
    edge->setNodes(beg,end);

    _Edges[_EdgeIndex] = edge;

    //nodesConnected(beg,end,edge);
    resetNodes();
}

void GraphWidget::resetGraphAppearance(bool hided)
{
    for(int i=0; i<= _NodeIndex; i++)
        setItemOpacity(i, GITEM_NODE, hided);

    for(int i=0; i<= _EdgeIndex; i++)
        setItemOpacity(i, GITEM_EDGE, hided);
}

void GraphWidget::setItemOpacity(int id, int itemType,  bool show)
{
    QGraphicsOpacityEffect* effect = new QGraphicsOpacityEffect();

    if(show)
        effect->setOpacity(1);
    else
        effect->setOpacity(0.25);

    if(itemType == GITEM_NODE && (id >=0 && id <= _NodeIndex))
        _Nodes[id]->setGraphicsEffect(effect);
    else if(itemType == GITEM_EDGE && (id >=0 && id <= _EdgeIndex))
        _Edges[id]->setGraphicsEffect(effect);


}

void GraphWidget::showArrowLabel()
{
    _bArrowLabel = true;
}

const Graph& GraphWidget::Graph(){
    return G;
}
