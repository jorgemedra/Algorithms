#include "frmpriorityqueue.h"
#include "ui_frmpriorityqueue.h"
#include <iostream>
#include <sstream>

using namespace collections;
using namespace std;

frmPriorityQueue::frmPriorityQueue(QWidget *parent, bool byMin) :
    QWidget(parent),
    ui(new Ui::frmPriorityQueue),
    heap(byMin)
{
    ui->setupUi(this);
    if(byMin)
        setWindowTitle("Priority Qeueu with HEAP Algorithm By Min.");
    else
        setWindowTitle("Priority Qeueu with HEAP Algorithm By Max.");

    scene =  new QGraphicsScene(this);
    ui->canvasViewe->setScene(scene);

    tree = new BinaryTreeBalanced(heap);

    itemSelected = 0;
    ui->cmdDelete->setEnabled(false);

}

frmPriorityQueue::~frmPriorityQueue()
{
    on_cmdPurgeQueue_clicked();
    delete ui;
    delete tree;
}


void frmPriorityQueue::on_cmdAddItem_clicked()
{
    stringstream steps;

    TreeNode* item = new TreeNode();
    item->ID = ui->txtKeyValue->text().toLong();
    heap.Insert(item->ID, item, steps);

    steps << endl;
    writeLog(steps.str());

    drawTable();
    drawTree();
}


void frmPriorityQueue::drawTable()
{
    QStringList listV;
    listV << "Heap Item Key";

    ui->tblHeap->clear();
    ui->tblHeap->setColumnCount(1);
    ui->tblHeap->setRowCount(heap.size());
    ui->tblHeap->setColumnWidth(0,120);
    ui->tblHeap->setHorizontalHeaderLabels(listV);


    for(size_t r=0; r < heap.size(); r++)
    {
        TreeNode* item = heap[r+1];
        QTableWidgetItem* it = ui->tblHeap->item(r,0);

        if(it == 0)
        {
            it = new QTableWidgetItem();
            ui->tblHeap->setItem(r, 0, it);
        }

        it->setText(QString::number(item->ID));
    }
}

void frmPriorityQueue::drawTree()
{
    for(int i=1; i<= heap.size(); i++)
        tree->drawNode(i, scene);
}

void frmPriorityQueue::on_tblHeap_clicked(const QModelIndex &index)
{
    stringstream out;
    itemSelected = index.row() + 1;
    out << "Delete Item: " << itemSelected;
    ui->cmdDelete->setText(out.str().c_str());
    ui->cmdDelete->setEnabled(true);
}

void frmPriorityQueue::on_cmdDelete_clicked()
{
    stringstream steps;
    bool success;
    TreeNode* item = heap.Delete(itemSelected, success, steps);

    steps << endl;
    writeLog(steps.str());

    if(success)
    {
        tree->deleteNode(item,scene);
        delete item;
    }
    itemSelected = 0;

    ui->cmdDelete->setEnabled(false);
    ui->cmdDelete->setText("Delete Item");

    drawTable();
    drawTree();
}

void frmPriorityQueue::writeLog(string log)
{
    QString data;

    data = ui->txtLog->toPlainText();
    data += log.c_str();
    ui->txtLog->setText(data);
}

void frmPriorityQueue::on_cmdClear_clicked()
{
    ui->txtLog->clear();
}


void frmPriorityQueue::on_cmdPurgeQueue_clicked()
{
    stringstream steps;
    stringstream out;
    long key;

    steps << "::::::::::::::::::::::::::::" << endl
          << "::: Steps to Purge Queue ::: " << endl
          << "::::::::::::::::::::::::::::" << endl;
    out << " ::: Queue Output Sequence:::" << endl << "\t[";

    while(heap.size() > 0)
    {
        bool success;
        TreeNode* node = heap.ExtractMin(success, steps);
        if(success)
        {
            out << " " << node->ID;
            tree->deleteNode(node,scene);
            delete node;
        }
    }
    out << "]" << endl;

    writeLog(steps.str());
    writeLog(out.str());

    drawTable();
    drawTree();
}
