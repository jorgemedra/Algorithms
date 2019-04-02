#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "help.h"
#include "frmabout.h"
#include "frmstablematching.h"
#include "frmpriorityqueue.h"
#include "frmgraphs.h"
#include "frmgraphpath.h"
#include "frmsort.h"
#include "frmcompress.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->mdiArea);
    Help::setQMdiArea(ui->mdiArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    Qt::WindowFlags flags = 0;

    frmAbout* about = new frmAbout(this);

    flags = about->windowFlags();
    flags &= ~flags;
    flags |= Qt::Sheet;

    about->setWindowFlags(flags);
    about->show();
/*
    MainWindow clone(this);
    clone.setWindowTitle("My Title");
    QString s1 = this->windowTitle();
    QString s2 = clone.windowTitle();

    return;
    */
}

void MainWindow::on_actionMain_Documentation_triggered()
{
    Help::openHelpWindow("https://github.com/jorgemedra/Algorithms/wiki");
}

void MainWindow::on_actionStable_Matching_triggered()
{
    frmStableMatching* wnd = new frmStableMatching(this);

    ui->mdiArea->addSubWindow(wnd);
    wnd->showMaximized();
}

void MainWindow::on_actionPriority_Queue_By_Min_triggered()
{
    frmPriorityQueue* wnd = new frmPriorityQueue(this);

    ui->mdiArea->addSubWindow(wnd);
    wnd->showMaximized();
}

void MainWindow::on_actionPriority_Queue_By_Max_triggered()
{
    frmPriorityQueue* wnd = new frmPriorityQueue(this,false);

    ui->mdiArea->addSubWindow(wnd);
    wnd->showMaximized();
}

void MainWindow::on_actionBSD_triggered()
{
    frmGraphFS* wnd = new frmGraphFS(false, this);

    ui->mdiArea->addSubWindow(wnd);
    wnd->showMaximized();
}

void MainWindow::on_actionBFS_DFS_directed_triggered()
{
    frmGraphFS* wnd = new frmGraphFS(true, this);

    ui->mdiArea->addSubWindow(wnd);
    wnd->showMaximized();
}

void MainWindow::on_actionShorter_Path_undirected_triggered()
{
    frmGraphPath* wnd = new frmGraphPath(false, this);

    ui->mdiArea->addSubWindow(wnd);
    wnd->showMaximized();
}

void MainWindow::on_actionShorter_Path_directed_triggered()
{
    frmGraphPath* wnd = new frmGraphPath(true, this);

    ui->mdiArea->addSubWindow(wnd);
    wnd->showMaximized();
}

void MainWindow::on_actionSorting_triggered()
{
    frmSort* wnd = new frmSort(this);

    ui->mdiArea->addSubWindow(wnd);
    wnd->showMaximized();
}

void MainWindow::on_actionCompress_triggered()
{
    frmCompress* wnd = new frmCompress(this);

    ui->mdiArea->addSubWindow(wnd);
    wnd->showMaximized();
}
