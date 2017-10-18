#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include<gnode.h>
#include<gedge.h>

#define MAX_GNODES      50
#define MAX_EDGES       1180

#define GITEM_NODE  0
#define GITEM_EDGE  1


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
    GEdge* _Edges[MAX_EDGES];

    bool bShift;
    bool _bDirected;
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

    void setDirectedGraph(bool bDirected);
    void resetGraphAppearance(bool hided);
    void setItemOpacity(int id, int itemType,  bool hided);


};

#endif // GRAPHWIDGET_H
