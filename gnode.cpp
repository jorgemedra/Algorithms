#include "gnode.h"
#include "gedge.h"
#include<cstdlib>
#include<iostream>
#include<sstream>

QBrush GNode::brushWhite(Qt::white);
QBrush GNode::brushGray(Qt::lightGray);
QPen GNode::penBlack(Qt::black);
QPen GNode::penBlue(Qt::blue);
QFont GNode::fontNode("Courier", 10);

GNode::GNode(QGraphicsItem *parent):
    QObject(0),
    QGraphicsEllipseItem(0,0,GNODE_WIDTH,GNODE_WIDTH,parent),
    _id(-1),
    _bSelected(false)
{
    _label.setParentItem(this);

    _label.setFont(fontNode);
    _label.setHtml("NA");

    setZValue(0);
    _label.setZValue(10);

    setBrush(GNode::brushWhite);
    setPen(GNode::penBlack);

    setFlags(QGraphicsItem::ItemIsMovable);

    QRectF br = boundingRect();
    QRectF brl = _label.boundingRect();

    int nx =  (br.width() - brl.width())/2;
    int ny =  (br.height() - brl.height()) / 2;
    _label.setX(_label.x() + nx);
    _label.setY(_label.y() + ny);
}


int GNode::getId()
{
    return _id;
}

void GNode::setId(int id)
{
    QString value;
    _id = id;
    _label.setHtml(value.setNum(id));
    _label.adjustSize();

}

void GNode::setSelected(bool selected)
{
    this->_bSelected = selected;

    if(this->_bSelected)
       setBrush(GNode::brushGray);
    else
        setBrush(GNode::brushWhite);
}

bool GNode::isSelected()
{
    return _bSelected;
}

void GNode::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    /*
    if(event->button() == Qt::LeftButton)
    {

        std::cout << "mouseMoveEvent: (IZQ) " << event->scenePos().x() << ":" << event->scenePos().y() << std::endl;
        std::cout << "\t ME: " << event->scenePos().x() << ":" << event->scenePos().y() << std::endl;
        setPos(event->scenePos().x() - (GNODE_WIDTH/2), event->scenePos().y() - (GNODE_WIDTH/2));

    }
    */
}

void GNode::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{

    if(event->button() == Qt::LeftButton)
    {
        emit pressed(this);
    }
}

void GNode::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    setPos(event->scenePos().x() - (GNODE_WIDTH/2), event->scenePos().y() - (GNODE_WIDTH/2));

    for(auto it = std::begin(_edges); it != std::end(_edges); it++)
    {
        GEdge* edge = *it;
        edge->updateByNode();
    }
    //emit moved(this);

}

void GNode::reset()
{
    setBrush(GNode::brushWhite);
    _bSelected = false;
}

int GNode::totalAdjacentNode()
{
    return adjacentNodes.size();
}

bool GNode::isAdjacentNode(GNode* node)
{
    for(auto it = std::begin(adjacentNodes); it != std::end(adjacentNodes); it++)
    {
        GNode* nAdj = *it;
        if(node == nAdj) return true;
    }

    return false;
}

void GNode::setAdjacentNode(GNode* node)
{
    if(!isAdjacentNode(node))
        adjacentNodes.push_back(node);
}

GNode* GNode::getAdjacentNode(int index)
{
    if(index < adjacentNodes.size())
        return adjacentNodes.at(index);
    return nullptr;
}

void GNode::setEdge(GEdge* edge)
{
    _edges.push_back(edge);
}
