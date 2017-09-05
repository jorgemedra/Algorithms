#ifndef BINARYTREEBALANCED_H
#define BINARYTREEBALANCED_H

#include <QGraphicsLineItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsEllipseItem>
#include"heap.h"

using namespace collections;

/**
 * @brief The PQItem class has the metadata of each Node element into the binary tree which is required to build the tree.
 */
class TreeNode : public HeapItem
{
public:
    int X=0;
    int Y=0;
    int CX=0;
    int CY=0;
    int NorhtY=0;
    int SouthY=0;
    QGraphicsLineItem* edge=nullptr;
    QGraphicsSimpleTextItem* label=nullptr;
    QGraphicsEllipseItem* circle=nullptr;
};

class BinaryTreeBalanced
{
    int const VerticalSpaceNode = 50;
    int const DiameterNode = 20;
    int const MinimalHorizonalSpace = 10 + DiameterNode;

    Heap* heap;

    int calculateLevel(int position);

public:
    BinaryTreeBalanced(Heap* h);
    void drawNode(int hPosition, QGraphicsScene* scene);

};

#endif // BINARYTREEBALANCED_H
