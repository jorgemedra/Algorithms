#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAbout_triggered();

    void on_actionMain_Documentation_triggered();

    void on_actionStable_Matching_triggered();

    void on_actionPriority_Queue_By_Min_triggered();

    void on_actionBSD_triggered();

    void on_actionBFS_DFS_directed_triggered();

    void on_actionPriority_Queue_By_Max_triggered();

    void on_actionShorter_Path_undirected_triggered();

    void on_actionShorter_Path_directed_triggered();

    void on_actionSorting_triggered();

    void on_actionCompress_triggered();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
