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
    void on_tblHeap_clicked(const QModelIndex &index);
    void on_cmdDelete_clicked();
    void on_cmdClear_clicked();

private:
    Ui::frmPriorityQueue *ui;

    QGraphicsScene* scene;

    Heap* heap;
    BinaryTreeBalanced* tree;
    int itemSelected;

    void drawTable();
    void drawTree();

    void writeLog(string log);


};

#endif // FRMPRIORITYQUEUE_H
