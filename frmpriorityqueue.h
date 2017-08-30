#ifndef FRMPRIORITYQUEUE_H
#define FRMPRIORITYQUEUE_H

#include "heap.h"
#include <QWidget>
#include <QGraphicsScene>

using namespace  collections;

namespace Ui {
class frmPriorityQueue;
}


/**
 * @brief The PQItem class has the metadata of each Node element into the binary tree which is required to build the tree.
 */
class TreeNode : HeapItem
{

public:

    int X=0;
    int Y=0;
    int CanvasX=0;
    int CanvasY=0;
    int NorhtY=0;
    int SouthY=0;
    int Widht=0;
    int Heigt=0;
    bool isLeftNode=true;
    QGraphicsLineItem* edgeToParent=nullptr;

    void changePositon(int x, int y){setPosition(x,y,Widht,Heigt);}

    void setPosition(int x, int y, int w, int h)
    {
        int aux = 0;
        X = x;
        Y = y;

        Widht=w;
        Heigt=h;

        aux = w/2;
        CanvasX = ( x >= 0 )? (x + aux): (x - aux);

        aux = h/2;
        CanvasY = ( y >= 0 )? (y + aux) : (y - aux);
        NorhtY = y + aux;
        SouthY = y - aux;

        isLeftNode = ((getHeapPosition()%2) == 0)? true : false;

    }
};


class frmPriorityQueue : public QWidget
{
    Q_OBJECT

public:
    explicit frmPriorityQueue(QWidget *parent = 0);
    ~frmPriorityQueue();

private:
    Ui::frmPriorityQueue *ui;

    QGraphicsScene* scene;
};

#endif // FRMPRIORITYQUEUE_H
