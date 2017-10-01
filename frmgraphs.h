#ifndef FRMGRAPHFS_H
#define FRMGRAPHFS_H

#include <QWidget>
#include <vector>
#include "graphwidget.h"
#include "tnode.h"

namespace Ui {
class frmGraphFS;
}

class frmGraphFS : public QWidget
{
    Q_OBJECT

public:
    explicit frmGraphFS(QWidget *parent = 0);
    ~frmGraphFS();

public slots:

    void errorRaised(int code);
    void nodeCreated(GNode* node);
    void nodesConnected(GNode* nodeIni, GNode* nodeFin, GEdge* edge);

private slots:
    void on_cmdBuildTree_clicked();

    void on_cmdClear_clicked();

private:
    Ui::frmGraphFS *ui;

    GraphWidget *widget;
    std::vector<TNode*> G; //Graph
    std::vector<TNode*> T; //Tree

    void writeLog(string log);
    void disposeGraph();
    void disposeTree();

};

#endif // FRMGRAPHFS_H
