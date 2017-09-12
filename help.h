#ifndef HELP_H
#define HELP_H

#include<QMdiArea>

class Help
{
    static QMdiArea* mdiArea;

public:
    Help();

    void static setQMdiArea(QMdiArea* area);

    void static openHelpWindow(QString url);
};

#endif // HELP_H

