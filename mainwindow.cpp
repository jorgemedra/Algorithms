#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "help.h"
#include "frmabout.h"
#include "frmstablematching.h"
#include "frmpriorityqueue.h"

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
}

void MainWindow::on_actionMain_Documentation_triggered()
{
    Help::openHelpWindow("https://guides.github.com/features/mastering-markdown/");
}

void MainWindow::on_actionStable_Matching_triggered()
{
    frmStableMatching* pmthc = new frmStableMatching(this);

    ui->mdiArea->addSubWindow(pmthc);
    pmthc->showMaximized();

}

void MainWindow::on_actionPriority_Queue_triggered()
{
    frmPriorityQueue* prtQueue = new frmPriorityQueue(this);

    ui->mdiArea->addSubWindow(prtQueue);
    prtQueue->showMaximized();
}
