#ifndef BINARYTREEBALANCED_H
#define BINARYTREEBALANCED_H

#include <QGraphicsLineItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsEllipseItem>
#include"heap.h"


/**
 * @brief The PQItem class has the metadata of each Node element into the binary tree which is required to build the tree.
 */
class TreeNode
{
public:
    TreeNode():ID{0},X{0},Y{0},CX{0},CY{0},NorhtY{0},SouthY{0},edge{nullptr},label{nullptr},circle{nullptr}{}
    long ID;
    int X;
    int Y;
    int CX;
    int CY;
    int NorhtY;
    int SouthY;
    QGraphicsLineItem* edge;
    QGraphicsSimpleTextItem* label;
    QGraphicsEllipseItem* circle;
};

class BinaryTreeBalanced
{
    int const VerticalSpaceNode{50};
    int const DiameterNode{20};
    int const MinimalHorizonalSpace{10 + DiameterNode};

    collections::Heap<TreeNode*>& heap;

    int calculateLevel(int position);

public:
    BinaryTreeBalanced(collections::Heap<TreeNode*>& h);
    void drawNode(int hPosition, QGraphicsScene* scene);
    void deleteNode(TreeNode* item, QGraphicsScene* scene);

};

#endif // BINARYTREEBALANCED_H
