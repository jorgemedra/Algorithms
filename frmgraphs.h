#ifndef FRMGRAPHFS_H
#define FRMGRAPHFS_H

#include <QWidget>
#include <vector>
#include "graphwidget.h"
#include "graphs.h"

namespace Ui {
class frmGraphFS;
}

class frmGraphFS : public QWidget
{
    Q_OBJECT

public:
    explicit frmGraphFS(bool directed, QWidget *parent = 0);
    ~frmGraphFS();

public slots:

    void errorRaised(int code);
    void nodeCreated(GNode* node);

private slots:
    void on_cmdBuildTree_clicked();
    void on_cmdClear_clicked();

private:
    Ui::frmGraphFS *ui;

    graphs::ui::GraphWidget *widget;

    bool _bDirected;
    void writeLog(string log);
};

#endif // FRMGRAPHFS_H
