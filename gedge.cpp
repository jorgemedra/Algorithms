#include "gedge.h"
#include "gnode.h"
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<cmath>

QPen GEdge::penBlack(Qt::black);
QPen GEdge::penLGray(Qt::lightGray);

#define RAD_ARROW      8
#define ANG_ARROW      30

GEdge::GEdge(QGraphicsItem* parent):
    QGraphicsLineItem(parent),
    _id(-1),
    _shade(false),
    _nBegin(nullptr),
    _nEnd(nullptr),
    _bArrow(false),
    _upAL(nullptr),
    _dnAL(nullptr)
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

void GEdge::showArrow(bool value)
{
    _bArrow = value;
}

void GEdge::setNodes(GNode* nBeg, GNode* nEnd)
{
    _nBegin = nBeg;
    _nEnd = nEnd;

    _upAL = new QGraphicsLineItem(this);
    _dnAL = new QGraphicsLineItem(this);

    _upAL->setLine(0,0,0,0);
    _dnAL->setLine(0,0,0,0);

    updateArrow(_bArrow);
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
    updateArrow(_bArrow);
}


void GEdge::updateArrow(bool showArrow)
{
    qreal PI = 3.14159265;
    qreal xB=0, xE=0;
    qreal yB=0, yE=0;
    qreal dX=0, dY=0, dH=0;
    qreal angR=0, angD=0;
    qreal aXB=0, aYB=0;
    qreal aUXE=0, aUYE=0, aDXE=0, aDYE=0;
    qreal angAux=0;

    _upAL->setVisible(showArrow);
    _dnAL->setVisible(showArrow);

    if(!showArrow) return;

    xB = _nBegin->pos().x() + (GNODE_WIDTH/2);
    xE = _nEnd->pos().x() + (GNODE_WIDTH/2);
    yB = _nBegin->pos().y() + (GNODE_WIDTH/2);
    yE = _nEnd->pos().y() + (GNODE_WIDTH/2);

    dX = abs(xB - xE);
    dY = abs(yB - yE);
    dH = sqrt(pow(dX,2) + pow(dY,2));

    angR = dY/dX;

    if(xE >= xB && yE >= yB ) //C1
        angD = atan(angR) * (180/PI);
    else if(xE >= xB && yE < yB ) //C2
        angD = 360 -(atan(angR) * (180/PI));
    else if(xE < xB && yE >= yB ) //C3
        angD =  180 - (atan(angR) * (180/PI));
    else if(xE < xB && yE < yB ) //C4
        angD = 180 + (atan(angR) * (180/PI));

    aXB = (dH - (GNODE_WIDTH/2)) * cos(angD*PI/180) + xB;
    aYB = (dH - (GNODE_WIDTH/2)) * sin(angD*PI/180) + yB;

    angAux = angD - 180 + ANG_ARROW;
    aUXE = RAD_ARROW * cos(angAux*PI/180) + aXB;
    aUYE = RAD_ARROW * sin(angAux*PI/180) + aYB;

    angAux = angD - 180 - ANG_ARROW;
    aDXE = RAD_ARROW * cos(angAux*PI/180) + aXB;
    aDYE = RAD_ARROW * sin(angAux*PI/180) + aYB;


    QLineF lineU;
    lineU.setLine(aXB, aYB, aUXE, aUYE);
    _upAL->setLine(lineU);
    _dnAL->setLine(aXB, aYB, aDXE, aDYE);

}
