#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include<gnode.h>
#include<gedge.h>

#define MAX_GNODES      50
#define MAX_EDGES       2500


class GraphWidget: public QGraphicsView
{
    Q_OBJECT

    enum ERROR{
        OK                  = 0,
        MAX_NODES_REACHED   = 1
    };

    QGraphicsScene* scene;

    int _NodeIndex;
    GNode* _Nodes[MAX_GNODES];
    int _EdgeIndex;
    GNode* _Edges[MAX_EDGES];

    bool bShift;
    int nSelected[2];
    int _countSel;
    void resetNodes();
    void connectNodes();

protected:

    void mouseDoubleClickEvent(QMouseEvent * event);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

signals:

    void errorRaised(int code);
    void nodeCreated(GNode* node);
    void nodesConnected(GNode* nodeIni, GNode* nodeFin, GEdge* edge);

public slots:

    void nodePressed(GNode* node);

public:
    GraphWidget(QWidget *parent = 0);

};

#endif // GRAPHWIDGET_H
