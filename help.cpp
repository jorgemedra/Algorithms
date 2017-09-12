#include<QWebEngineView>
#include<QMdiArea>
#include<QUrl>

#include "help.h"

QMdiArea* Help::mdiArea=nullptr;

void Help::setQMdiArea(QMdiArea* area){
    Help::mdiArea = area;
}

void Help::openHelpWindow(QString url){
    QWebEngineView *doc = new QWebEngineView();
    Help::mdiArea->addSubWindow(doc);
    doc->showNormal();
    doc->load(QUrl(url));

}
