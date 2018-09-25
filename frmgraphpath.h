#ifndef FRMGRAPHPATH_H
#define FRMGRAPHPATH_H

#include <QWidget>
#include <vector>
#include "graphwidget.h"
#include "pthnode.h"

namespace Ui {
class frmGraphPath;
}

class frmGraphPath : public QWidget
{
    Q_OBJECT

public:
    explicit frmGraphPath(bool directed, QWidget *parent = 0);
    ~frmGraphPath();

public slots:

    void errorRaised(int code);
    void nodeCreated(GNode* node);
    void nodesConnected(GNode* nodeIni, GNode* nodeFin, GEdge* edge);
    void nodeMoved(GNode* node);

private:
    Ui::frmGraphPath *ui;

    GraphWidget *widget;

    bool _bDirected;
    std::vector<PathNode> G; //Graph

};

#endif // FRMGRAPHPATH_H
