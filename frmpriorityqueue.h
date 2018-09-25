#ifndef FRMPRIORITYQUEUE_H
#define FRMPRIORITYQUEUE_H

#include "heap.h"
#include "binarytreebalanced.h"
#include <QWidget>
#include <QGraphicsScene>

namespace Ui {
class frmPriorityQueue;
}

class frmPriorityQueue : public QWidget
{
    Q_OBJECT

public:
    explicit frmPriorityQueue(QWidget *parent = 0, bool byMin=true);
    ~frmPriorityQueue();

private slots:
    void on_cmdAddItem_clicked();
    void on_tblHeap_clicked(const QModelIndex &index);
    void on_cmdDelete_clicked();
    void on_cmdClear_clicked();
    void on_cmdPurgeQueue_clicked();

private:
    Ui::frmPriorityQueue *ui;

    QGraphicsScene* scene;

    collections::Heap<TreeNode*> heap;
    BinaryTreeBalanced* tree;
    int itemSelected;

    void drawTable();
    void drawTree();

    void writeLog(std::string log);
};

#endif // FRMPRIORITYQUEUE_H
