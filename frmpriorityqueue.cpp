#include "frmpriorityqueue.h"
#include "ui_frmpriorityqueue.h"
#include <iostream>
#include <sstream>

using namespace collections;
using namespace std;

frmPriorityQueue::frmPriorityQueue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmPriorityQueue)
{
    ui->setupUi(this);
    setWindowTitle("Priority Qeueu with HEAP Algorithm");

    scene =  new QGraphicsScene(this);
    ui->canvasViewe->setScene(scene);

    heap = new Heap;
    tree = new BinaryTreeBalanced(heap);

    itemSelected = 0;
    ui->cmdDelete->setEnabled(false);

    //scene->addEllipse(0,0,10,10);
    //scene->addEllipse(-20,20,2,2);
    //scene->addEllipse(20,20,5,5);
    //scene->setSceneRect(-2500,-2500,5000,5000);

}

frmPriorityQueue::~frmPriorityQueue()
{
    delete ui;
    delete tree;
    delete heap;
}


void frmPriorityQueue::on_cmdAddItem_clicked()
{
    stringstream steps;

    TreeNode* item = new TreeNode();
    item->setKey(ui->txtKeyValue->text().toLong());
    heap->Insert(item,steps);

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
    ui->tblHeap->setRowCount(heap->size());
    ui->tblHeap->setColumnWidth(0,120);
    ui->tblHeap->setHorizontalHeaderLabels(listV);


    for(int r=0; r < heap->size(); r++)
    {
        HeapItem* item = heap->operator [](r+1);
        QTableWidgetItem* it = ui->tblHeap->item(r,0);

        if(it == 0)
        {
            it = new QTableWidgetItem();
            ui->tblHeap->setItem(r, 0, it);
        }

        it->setText(QString::number(item->getKey()));
    }
}

void frmPriorityQueue::drawTree()
{
    for(int i=1; i<= heap->size(); i++)
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

    TreeNode* item = (TreeNode*)heap->Delete(itemSelected, steps);

    steps << endl;
    writeLog(steps.str());

    if(item != nullptr)
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
