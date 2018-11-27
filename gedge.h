#ifndef GEDGE_H
#define GEDGE_H


#include <QGraphicsLineItem>
#include <QBrush>
#include <QFont>
#include <QPen>
#include <QObject>

class GNode;

class GEdge : public QObject, public QGraphicsLineItem
{
    Q_OBJECT

    static QPen   penBlack;
    static QPen   penLGray;

    int _id;
    bool _shade;
    GNode* _nBegin;
    GNode* _nEnd;

    bool _bArrow;
    bool _bLabelArw;
    QGraphicsLineItem* _upAL;
    QGraphicsLineItem* _dnAL;
    QGraphicsTextItem _label;
    long _Longitud;

    void updateArrow();
    void updateLabel();

signals:
    void longitudChanged(int id, long newL);

public:
    GEdge(QGraphicsItem *parent=0);

    void setShade(bool shade);
    bool getShade();
    void setId(int);
    int getId();
    void showArrow(bool value);
    void showLabel(bool value);
    void setNodes(GNode* nBeg, GNode* nEnd);
    GNode* getNode(bool isBegin);
    void updateByNode();

    long getLongitud();
};

#endif // GEDGE_H
