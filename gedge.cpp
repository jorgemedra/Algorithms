#include "gedge.h"
#include "gnode.h"
#include<cstdlib>
#include<iostream>
#include<sstream>


QPen GEdge::penBlack(Qt::black);
QPen GEdge::penLGray(Qt::lightGray);

GEdge::GEdge(QGraphicsItem* parent):
    QGraphicsLineItem(parent),
    _id(-1),
    _shade(false),
    _nBegin(nullptr),
    _nEnd(nullptr)
{
    setPen(penBlack);
}

void GEdge::setShade(bool shade)
{
    _shade = shade;

    if(_shade)
        setPen(penLGray);
    else
        setPen(penBlack);
}

bool GEdge::getShade()
{
    return _shade;
}

void GEdge::setId(int id)
{
    _id=id;
}

int GEdge::getId()
{
    return _id;
}

void GEdge::setNodes(GNode* nBeg, GNode* nEnd)
{
    _nBegin = nBeg;
    _nEnd = nEnd;
}

GNode* GEdge::getNode(bool isBegin)
{
    return (isBegin)? _nBegin:_nEnd;
}

void GEdge::updateByNode()
{
    QLineF line;
    line.setLine(_nBegin->pos().x() + (GNODE_WIDTH/2), _nBegin->pos().y() + (GNODE_WIDTH/2),
                 _nEnd->pos().x() + (GNODE_WIDTH/2), _nEnd->pos().y() + (GNODE_WIDTH/2));
    setLine(line);
}
