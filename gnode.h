#ifndef GNODE_H
#define GNODE_H


#include <QGraphicsSceneMouseEvent>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QObject>
#include <QBrush>
#include <QFont>
#include <QPen>
#include <vector>

#define GNODE_WIDTH     40

using namespace std;

class GEdge;

class GNode : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT

    static QBrush brushWhite;//(Qt::white);
    static QBrush brushGray;//(Qt::lightGray);
    static QPen   penBlack;//(Qt::black);
    static QPen   penBlue;//(Qt::blue);
    static QFont  fontNode;

    QGraphicsTextItem _label;
    int _id;
    bool _bSelected;

    vector<GNode*> adjacentNodes;
    vector<GEdge*> _edges;


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

signals:
    void pressed(GNode* node);
    void moved(GNode* node);

public:
    GNode(QGraphicsItem *parent=0);

    int getId();
    void setId(int id);
    void setSelected(bool selected);
    bool isSelected();
    void reset();

    int totalAdjacentNode();
    bool isAdjacentNode(GNode* node);
    void setAdjacentNode(GNode* node);
    GNode* getAdjacentNode(int index);
    void setEdge(GEdge* edge);
};
#endif // GNODE_H
