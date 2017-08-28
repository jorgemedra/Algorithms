#ifndef FRMABOUT_H
#define FRMABOUT_H

#include <QWidget>
#include <QMdiSubWindow>

namespace Ui {
class frmAbout;
}

class frmAbout : public QWidget
{
    Q_OBJECT

public:
    explicit frmAbout(QWidget *parent = 0);
    ~frmAbout();

private slots:
    void on_pushButton_clicked();
    //void on_windowStateChanged(Qt::WindowStates oldState, Qt::WindowStates newState);


protected:
    //void changeEvent(QEvent *event);

private:
    Ui::frmAbout *ui;

};

#endif // FRMABOUT_H
