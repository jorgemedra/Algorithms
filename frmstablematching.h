#ifndef FRMPERFECTMATCHING_H
#define FRMPERFECTMATCHING_H

#include <QWidget>
#include<QTableWidget>
#include<sstream>

namespace Ui {
class frmPerfectMatching;
}

using namespace std;

class frmStableMatching : public QWidget
{
    Q_OBJECT

public:
    explicit frmStableMatching(QWidget *parent = 0);
    ~frmStableMatching();

private slots:
    void on_cmdBuildModel_clicked();


    void on_pushButton_clicked();

    void on_cmdClear_clicked();

private:
    Ui::frmPerfectMatching *ui;
    int _size;

    void buildPreference(QTableWidget* tables, string prefRow, string prefCol );

    int* stableMatching(int size, int** manPref, int** womanPref, stringstream& steps);

};

#endif // FRMPERFECTMATCHING_H
