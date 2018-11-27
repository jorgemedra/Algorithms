#ifndef FRMGRAPHPATH_H
#define FRMGRAPHPATH_H

#include <QWidget>
#include <vector>
#include "graphwidget.h"
#include "graphs.h"

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
    //void nodeCreated(GNode* node);
    //void nodesConnected(GNode* nodeIni, GNode* nodeFin, GEdge* edge);
    //void nodeMoved(GNode* node);

private:
    Ui::frmGraphPath *ui;

    graphs::ui::GraphWidget *widget;

    bool _bDirected;

};

#endif // FRMGRAPHPATH_H
