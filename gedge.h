#ifndef GEDGE_H
#define GEDGE_H


#include <QGraphicsLineItem>
#include <QBrush>
#include <QFont>
#include <QPen>

class GNode;

class GEdge : public QGraphicsLineItem
{
    static QPen   penBlack;
    static QPen   penLGray;

    int _id;
    bool _shade;
    GNode* _nBegin;
    GNode* _nEnd;

public:
    GEdge(QGraphicsItem *parent=0);

    void setShade(bool shade);
    bool getShade();
    void setId(int);
    int getId();
    void setNodes(GNode* nBeg, GNode* nEnd);
    GNode* getNode(bool isBegin);
    void updateByNode();

};

#endif // GEDGE_H
