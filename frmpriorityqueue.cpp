#include "frmpriorityqueue.h"
#include "ui_frmpriorityqueue.h"

#include <QBrush>
#include <QPen>


frmPriorityQueue::frmPriorityQueue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmPriorityQueue)
{
    ui->setupUi(this);



    scene =  new QGraphicsScene(this);
    ui->canvasViewe->setScene(scene);

    QBrush bBlack(Qt::black);
    QBrush bGray(Qt::lightGray);
    QPen   blackPen(Qt::black);
    blackPen.setWidth(1);

    scene->addEllipse(10,10,50,50,blackPen,bGray);
    scene->addEllipse(10,10,50,50,blackPen,bGray);
    scene->addText("1");


}

frmPriorityQueue::~frmPriorityQueue()
{
    delete ui;
}

