#ifndef FRMPRIORITYQUEUE_H
#define FRMPRIORITYQUEUE_H

#include "binarytreebalanced.h"
#include <QWidget>
#include <QGraphicsScene>
#include "heap.h"

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

    void on_tblHeap_cellChanged(int row, int column);

    void on_tblHeap_cellEntered(int row, int column);

private:
    Ui::frmPriorityQueue *ui;

    QGraphicsScene* scene;

    collections::Heap<TreeNode*> heap;
    BinaryTreeBalanced* tree;
    size_t itemSelected;

    void drawTable();
    void drawTree();

    void writeLog(std::string log);
};

#endif // FRMPRIORITYQUEUE_H
