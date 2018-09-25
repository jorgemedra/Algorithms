#include "frmsort.h"
#include "ui_frmsorts.h"
#include "sortalgorithms.h"

#include <iostream>
#include <sstream>

using namespace std;



vector<Sort::Algorithm> frmSort::Algorithms {
    {"Gnome Sort", Sort::ALG_CODE::Gnome },
    {"Insertion Sort", Sort::ALG_CODE::Insertion },
    {"Selection Sort", Sort::ALG_CODE::Selection},
    {"Buble Sort",  Sort::ALG_CODE::Buble},
    {"Merge Sort",  Sort::ALG_CODE::Merge},
    {"Quick Sort",  Sort::ALG_CODE::Quick}
};


frmSort::frmSort(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmSort)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    for(Sort::Algorithm a:Algorithms)
        ui->cmbAlgorithm->addItem(a.name,a.code);

}


frmSort::~frmSort()
{
    cout << "~frmSort" << endl;
    delete ui;
}

void frmSort::on_cmdGenerate_clicked()
{
    stringstream out;
    int size = ui->spnInput->value();
    for(int i=size; i>=1; i--)
        out << (i<size ? " " : "") << i;

    ui->txtInput->setPlainText(QString(out.str().c_str()));
}

void frmSort::on_cmdClearInput_clicked()
{
    ui->txtInput->setPlainText("");
}

void frmSort::on_cmdClear_clicked()
{
    ui->txtLog->setPlainText("");
}

void frmSort::parseInput(vector<int>& v)
{
    string token;
    stringstream in;

    v.clear();
    in << ui->txtInput->toPlainText().toStdString();

    while( getline(in,token,' ') )
    {
        int value = std::atoi(token.c_str());
        v.push_back(value);
    }
}

void frmSort::on_cmdRun_clicked()
{
    stringstream out;
    vector<int> serie{};

    parseInput(serie);

    if(serie.size() <= 0)
    {
        writeLog("There is no a valid input to sort.\n");
        return;
    }

    int index = ui->cmbAlgorithm->currentIndex();
    index = index<0? 0:index;

    int code = ui->cmbAlgorithm->itemData(index).toInt();
    QString name = ui->cmbAlgorithm->itemText(index);

    out << "Executing Sort Algorithm: " << name.toStdString() << "[" << code << "]" << endl;
    writeLog(out.str());
    out.str("");

    size_t size = serie.size();


    if(code == Sort::ALG_CODE::Gnome) //Gnome Sort
    {
        sort::Gnome<int> sortAlg;
        sort::Sort(size, serie.begin(), serie.end(), sortAlg, out);
    }
    else if(code == Sort::ALG_CODE::Insertion) //Intertion Sort
    {
        sort::Insertion<int> sortAlg;
        sort::Sort(size, serie.begin(), serie.end(), sortAlg, out);
    }
    else if(code == Sort::ALG_CODE::Selection) //Selection Sort
    {
        sort::Selection<int> sortAlg;
        sort::Sort(size, serie.begin(), serie.end(), sortAlg, out);
    }
    else if(code == Sort::ALG_CODE::Buble) //Buble Sort
    {
        sort::Bubble<int> sortAlg;
        sort::Sort(size, serie.begin(), serie.end(), sortAlg, out);
    }
    else if(code == Sort::ALG_CODE::Merge) //MERGE Sort
    {
        sort::Merge<int> sortAlg;
        sort::Sort(size, serie.begin(), serie.end(), sortAlg, out);
    }
    else if(code == Sort::ALG_CODE::Quick) //Quick Sort
    {
        sort::Quick<int> sortAlg;
        sort::Sort(size, serie.begin(), serie.end(), sortAlg, out);
    }

    out << "\tSorted Output:" << endl << "\t[";

    for(int x:serie)
       out << x << " ";
    out <<"]" << endl << endl;

    writeLog(out.str());
}




void frmSort::writeLog(string log)
{
    QString data;

    data = ui->txtLog->toPlainText();
    data += log.c_str();
    ui->txtLog->setPlainText(data);
}
