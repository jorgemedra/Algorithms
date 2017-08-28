#ifndef FRMDOCUMENTATION_H
#define FRMDOCUMENTATION_H

#include <QWidget>

namespace Ui {
class frmDocumentation;
}

class frmDocumentation : public QWidget
{
    Q_OBJECT

public:
    explicit frmDocumentation(QWidget *parent = 0);
    ~frmDocumentation();

private:
    Ui::frmDocumentation *ui;
};

#endif // FRMDOCUMENTATION_H
