#ifndef FRMCOMPRESS_H
#define FRMCOMPRESS_H

#include <QWidget>
#include<atomic>
#include<thread>
#include"huffman.h"

namespace Ui {
class frmCompress;
}

class frmCompress : public QWidget
{
    Q_OBJECT

public:
    explicit frmCompress(QWidget *parent = 0);
    ~frmCompress();

    void running();

public slots:
    void progess(int type , double percent);
    void writeLog(QString log);

private slots:
    void on_cmdProcess_clicked();

    void on_pushButton_clicked();

private:
    Ui::frmCompress *ui;
    std::atomic<bool> isRunning;


    huffman::ProgressNotify notifier;
    std::thread t;

};



#endif // FRMCOMPRESS_H
