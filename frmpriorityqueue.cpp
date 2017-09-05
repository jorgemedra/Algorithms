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

    scene =  new QGraphicsScene(this);
    ui->canvasViewe->setScene(scene);

    heap = new Heap;
    tree = new BinaryTreeBalanced(heap);

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
    stringstream out;

    TreeNode* item = new TreeNode();
    item->setKey(ui->txtKeyValue->text().toLong());
    heap->Insert(item,out);
    cout << out.str() << endl;

    drawTree();
}



void frmPriorityQueue::drawTree()
{
    for(int i=1; i<= heap->size(); i++)
        tree->drawNode(i, scene);
}
