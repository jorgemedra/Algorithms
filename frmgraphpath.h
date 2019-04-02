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
    void nodeCreated(GNode* node);

private slots:
    void on_cmdFind_clicked();

    void on_cmdClear_clicked();

    void on_optDjskt_clicked();

    void on_optPrim_clicked();

    void on_optKruskal_clicked();

    void on_optCluster_clicked();

private:
    Ui::frmGraphPath *ui;

    graphs::ui::GraphWidget *widget;

    bool _bDirected;
    void writeLog(string log);

    void selectOption();

    void procDijkstra(long from, long to);
    void procPRIM(long from);
    void procKruskatCluster(long size = 0, bool isCluster = false);


};

#endif // FRMGRAPHPATH_H
