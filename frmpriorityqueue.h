#ifndef FRMPRIORITYQUEUE_H
#define FRMPRIORITYQUEUE_H

#include "heap.h"
#include "binarytreebalanced.h"
#include <QWidget>
#include <QGraphicsScene>

using namespace  collections;

namespace Ui {
class frmPriorityQueue;
}



class frmPriorityQueue : public QWidget
{
    Q_OBJECT

public:
    explicit frmPriorityQueue(QWidget *parent = 0);
    ~frmPriorityQueue();



private slots:
    void on_cmdAddItem_clicked();

private:
    Ui::frmPriorityQueue *ui;

    QGraphicsScene* scene;

    Heap* heap;
    BinaryTreeBalanced* tree;

    void drawTree();


};

#endif // FRMPRIORITYQUEUE_H
