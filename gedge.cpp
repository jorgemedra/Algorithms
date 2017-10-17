#include "gedge.h"
#include "gnode.h"
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<cmath>

QPen GEdge::penBlack(Qt::black);
QPen GEdge::penLGray(Qt::lightGray);

#define RARROW      4
#define AARROW       30

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
    qreal xB, xE;
    qreal yB, yE;
    qreal dX, dY, dH;
    qreal angR, angD;
    qreal aXB, aYB;
    qreal aUXE, aUYE, aDXE, aDYE;
    qreal angAux;
    int cId = 0;

    xB = _nBegin->pos().x() + (GNODE_WIDTH/2);
    xE = _nEnd->pos().x() + (GNODE_WIDTH/2);
    yB = _nBegin->pos().y() + (GNODE_WIDTH/2);
    yE = _nEnd->pos().y() + (GNODE_WIDTH/2);

    dX = abs(xB - xE);
    dY = abs(yB - yE);
    dH = sqrt(pow(dX,2) + pow(dY,2));

    angR = dY/dX;
    //turn clockwise to set each Secction (C1 - C4)
    if(xE >= xB && yE < yB ) //C1
    {
        cout << "C1" << endl;
        angD = atan(angR) * (180/PI);
        cId = 1;
    }
    else if(xE >= xB && yE >= yB ) //C2
    {
        cout << "C2" << endl;
        angD = 360 -(atan(angR) * (180/PI));
        cId = 2;
    }
    else if(xE < xB && yE >= yB ) //C3
    {
        cout << "C3" << endl;
        angD = (atan(angR) * (180/PI)) + 180;
        cId = 3;
    }
    else if(xE < xB && yE < yB ) //C4
    {
        cout << "C4" << endl;
        angD = 180 - (atan(angR) * (180/PI));
        cId = 4;
    }


    aXB = (dH - (GNODE_WIDTH/2)) * cos(angD) + xB;
    aYB = (dH - (GNODE_WIDTH/2)) * sin(angD) + yB;

    if(cId == 1)
    {
        //angAux = angD + 180 - AARROW;
        angAux = angD + AARROW;
        //aUXE = RARROW * cos(angAux) + aXE;
        //aUYE = RARROW * sin(angAux) + aYE;
        aUXE = (dH - (GNODE_WIDTH/2) - AARROW) * cos(angD) + xB;
        aUYE = (dH - (GNODE_WIDTH/2) - AARROW) * sin(angD) + yB;


        //angAux = angD + 180 + AARROW;
        angAux = angD - AARROW;
        /*
        aDXE = RARROW * cos(angAux) + aXB;
        aDYE = RARROW * sin(angAux) + aYB;
        */
        aDXE = (dH - (GNODE_WIDTH/2) - AARROW) * cos(angD) + xB;
        aDYE = (dH - (GNODE_WIDTH/2) - AARROW) * sin(angD) + yB;
    }

    _upAL->setLine(aXB, aYB, aUXE, aUYE);
    _dnAL->setLine(aXB, aYB, aDXE, aDYE);

    cout << "angle: " << angD << endl;


}
