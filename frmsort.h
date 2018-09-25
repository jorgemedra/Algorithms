#ifndef FRMSORT_H
#define FRMSORT_H

#include <QWidget>
#include <QMdiSubWindow>
#include <string>

namespace Ui {
class frmSort;
}

namespace Sort
{
    enum ALG_CODE : int
    {
        Gnome = 0,
        Insertion,
        Selection,
        Buble,
        Merge,
        Quick,
    };

    struct Algorithm{
        const char* name;
        const int code;
    };

}

class frmSort : public QWidget
{
    Q_OBJECT
public:
    explicit frmSort(QWidget *parent = 0);
    ~frmSort();

    Ui::frmSort *ui;

signals:

public slots:

private slots:
    void on_cmdGenerate_clicked();
    void on_cmdClearInput_clicked();
    void on_cmdClear_clicked();

    void on_cmdRun_clicked();

private:

    static std::vector<Sort::Algorithm> Algorithms;

    void parseInput(std::vector<int>& v);
    void writeLog(std::string log);


};

#endif // FRMSORT_H
