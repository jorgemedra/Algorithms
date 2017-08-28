#ifndef FRMPRIORITYQUEUE_H
#define FRMPRIORITYQUEUE_H

#include <QWidget>
#include <QGraphicsScene>

namespace Ui {
class frmPriorityQueue;
}


/**
 * @brief The PQItem class has the metadata of each Node element into the binary tree which is required to build the tree.
 */
struct TreeNode
{
    int childsCount = 0;
    int CanvasX=0;
    int CanvasY=0;
    int CentralX=0;
    int CentralY=0;
    int PointYPos=0;
    int PointYMin=0;
    int Widht=0;
    int Heigt=0;

    void setPosition(int x, int y, int w, int h)
    {
        int aux = 0;
        CanvasX = x;
        CanvasY = y;

        Widht=w;
        Heigt=h;

        aux = w/2;
        if( x >= 0 ) CentralX = x + aux;
        else CentralX = x - aux;

        aux = h/2;
        if( y >= 0 ) CentralY = y + aux;
        else CentralY = y - aux;
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
