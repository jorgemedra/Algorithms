#include "frmcompress.h"
#include "ui_frmcompress.h"
#include "huffman.h"
#include<thread>

using namespace std;
using namespace std::placeholders;
using namespace huffman;

frmCompress::frmCompress(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmCompress),
    isRunning{false},
    notifier{}
{
    ui->setupUi(this);

    ui->pBarProgress->setMinimum(0);
    ui->pBarProgress->setMaximum(100);
    ui->pBarProgress->setValue(0);

    connect(&notifier, SIGNAL(siglProgress(int,double)), this, SLOT(progess(int,double)));
    connect(&notifier, SIGNAL(sgnlLog(QString)),this,SLOT(writeLog(QString)));
}

frmCompress::~frmCompress()
{
    if(t.joinable())
        t.join();


    disconnect(&notifier, SIGNAL(siglProgress(int,double)), this, SLOT(progess(int,double)));
    disconnect(&notifier, SIGNAL(sgnlLog(QString)),this,SLOT(writeLog(QString)));
    delete ui;
}

void frmCompress::on_cmdProcess_clicked()
{

    if(!isRunning)
        t = std::thread (&frmCompress::running, this);
    else
        writeLog("The process is already running.");
}

void frmCompress::running()
{
    huffman::CodecTable codec;

    string inputPath = ui->txtInputPath->toPlainText().toStdString();
    string compPath = inputPath + ".comp";
    string outputPath = ui->txtOutPath->toPlainText().toStdString();

    if(codec.build(inputPath, notifier))
    {
        huffman::tool::Compress(codec,inputPath,compPath, notifier);
        huffman::tool::Uncompress(codec, compPath, outputPath, notifier);
    }
    ui->lbProgress->setText("Done.");
    notifier.notifyLog("Done.");
    return;
}

void frmCompress::progess(int type , double percent)
{
    switch (type)
    {
        case huffman::ProgressType::flwScanning:
            ui->lbProgress->setText("Scanning...");
            break;
        case huffman::ProgressType::flwCompress:
            ui->lbProgress->setText("Compressing...");
            break;
        case huffman::ProgressType::flwBuildingPTree:
            ui->lbProgress->setText("Building Tree Key...");
            break;
        case huffman::ProgressType::flwUncompress:
            ui->lbProgress->setText("Uncompressing...");
            break;
        default:
            ui->lbProgress->setText("Done.");
            break;
    }
    ui->pBarProgress->setValue(static_cast<int>(percent));
}


void frmCompress::writeLog(QString log)
{
    QString data;

    data = ui->txtLogs->toPlainText();
    data += log;
    data += "\n";
    ui->txtLogs->setText(data);
}

void frmCompress::on_pushButton_clicked()
{
    ui->txtLogs->setText("");
}
