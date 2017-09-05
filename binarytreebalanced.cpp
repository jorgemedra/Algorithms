#include <cmath>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QBrush>
#include <QPen>
#include "binarytreebalanced.h"

#include <iostream>

using namespace collections;

BinaryTreeBalanced::BinaryTreeBalanced(Heap* heap)
{
    this->heap = heap;
}

int BinaryTreeBalanced::calculateLevel(int position)
{
    int lvl=0, min=0,max=0;
    if(position < 1 || position > heap->size()) return 0;

    for(lvl=0; lvl <= heap->levels(); lvl++)
    {
        min= pow(2,lvl);
        max = 2*min - 1;

        if(position >= min && position <= max)
            return lvl;
    }

    return lvl;
}

void BinaryTreeBalanced::drawNode(int hPosition, QGraphicsScene* scene)
{
    TreeNode* node = nullptr;
    TreeNode* parent = nullptr;
    int aLevel = 0, dLevel = 0; //Ascendin Level, Descending Level
    int parentX=0, parentY=0;
    QBrush bGray(Qt::lightGray);
    QPen   blackPen(Qt::black);
    QPen   bluePen(Qt::blue);

    if(hPosition < 1 || hPosition > heap->size()) return;

    if(hPosition > 1)
    {
        aLevel = calculateLevel(hPosition);
        dLevel = (heap->levels()-1) - aLevel;
        parent = (TreeNode*)heap->operator [](hPosition/2);
        parentX = parent->X;
        parentY = parent->Y;
        //cout << "Parent: " << hPosition/2 << " aLevel: " << aLevel << " dLevel: " << dLevel << endl;
    }

    //1.- Calculate Coordinates
    node = (TreeNode*)heap->operator [](hPosition);

    bool isLeftNode = ((hPosition%2) == 0)? true:false;
    int vSpace = aLevel * VerticalSpaceNode;
    int hSpace = (aLevel==0)? 0 : MinimalHorizonalSpace * std::pow(2,dLevel); //Horizontal Space Beteween nodes, it depends of node's level.
    int halfSpc = DiameterNode/2;

    node->Y = vSpace;
    node->X = (isLeftNode)? parentX - (hSpace/2) : parentX + (hSpace/2);

    node->CX = node->X - halfSpc; //( node->X >= 0 )? (node->X - halfSpc): (node->X + halfSpc);
    node->CY = node->Y - halfSpc; //( node->Y >= 0 )? (node->Y + halfSpc) : (node->Y - halfSpc);

    node->NorhtY = node->Y - halfSpc;
    node->SouthY = node->Y + halfSpc;

    //2.- Draw Node
    if(node->circle == nullptr)
    {
        node->circle = scene->addEllipse(0, 0, DiameterNode, DiameterNode, blackPen, bGray);
        node->label = scene->addSimpleText("");
        node->label->setParentItem(node->circle);
        node->label->setPos(halfSpc/2, 2);
        node->edge = scene->addLine(0,0,0,0,bluePen);
        node->circle->setFlags(QGraphicsItem::ItemIsMovable);
    }

    node->circle->setPos(node->CX, node->CY);
    node->label->setText(QString::number(node->getKey()));

    if(aLevel<=0)
        node->edge->setVisible(false);
    else
    {
        node->edge->setLine(node->X,node->NorhtY, parent->X,parent->SouthY);
        node->edge->setVisible(true);
    }

    std::cout << "ITEM: " << hPosition << ": [x,y]=[" << node->X << ", " << node->Y << "] aLevel: " << aLevel << " dLevel: " << dLevel  << " Levels: " << heap->levels() << std::endl;
}
