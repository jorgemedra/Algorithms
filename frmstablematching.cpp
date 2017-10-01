#include "frmstablematching.h"
#include "ui_frmstablematching.h"

#include<QSet>
#include<QStringList>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<stack>

using namespace std;

frmStableMatching::frmStableMatching(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmPerfectMatching)
{
    ui->setupUi(this);
    setWindowTitle("Stable Matching Algorithm");
    ui->txtSize->setText("3");
    _size = 0;
}

frmStableMatching::~frmStableMatching()
{
    cout << "~frmPerfectMatching" << endl;
    delete ui;
}

void frmStableMatching::on_cmdBuildModel_clicked()
{
   _size = ui->txtSize->text().toUInt();

   ui->tblManPref->clear();
   ui->tblManPref->setWindowTitle("Hombres");
   ui->tblManPref->setColumnCount(_size);
   ui->tblManPref->setRowCount(_size);


   buildPreference(ui->tblManPref, "man", "Pw");

   ui->tblWomanPref->clear();
   ui->tblWomanPref->setColumnCount(_size);
   ui->tblWomanPref->setRowCount(_size);

   buildPreference(ui->tblWomanPref, "woman", "Pm");

   ui->tblMatch->clear();
   ui->tblMatch->setRowCount(_size);

}

void frmStableMatching::buildPreference(QTableWidget* table, string prefRow, string prefCol)
{
    stringstream aux;
    QStringList listH;
    QStringList listV;

    for(int r=0; r < _size; r++)
    {
        aux.str("");
        aux <<  prefRow << " " << (r+1);
        QString rstr(aux.str().c_str());
        listV << rstr;

        for(int c=0; c < _size; c++)
        {
            aux.str("");
            aux <<  prefCol << " " << (c+1);
            QString cstr(aux.str().c_str());
            listH << cstr;

            QSet<int> unorderContainer;

            for(int prf=1; prf <= _size; prf++)
                unorderContainer.insert(prf);

            QList<int> pref = unorderContainer.toList();

            stringstream out;

            if(r==0)
                table->setColumnWidth(c,50);

            out << pref[c] << endl;
            QString data;
            data = out.str().c_str();
            QTableWidgetItem* it = table->item(r,c);

            if(it == 0)
            {
                it = new QTableWidgetItem();
                table->setItem(r, c, it);
            }
            it->setText(data);
        }
    }

    table->setHorizontalHeaderLabels(listH);
    table->setVerticalHeaderLabels(listV);
}

void frmStableMatching::on_pushButton_clicked()
{
    int i,j;
    int* women;
    int** manPref = NULL;
    int** womanPref= NULL;

    stringstream aux;
    QStringList listH;
    QStringList listV;


    manPref = new int* [_size];
    womanPref = new int* [_size];

    for(i=0; i < _size; i++)
    {
        manPref[i] = new int[_size];
        womanPref[i] = new int[_size];

        for(j=0; j < _size; j++)
        {
            QTableWidgetItem* qit = ui->tblManPref->item(i,j);
            QString data = qit->text();
            manPref[i][j] = data.toInt() - 1; //All the index are base 0

            qit = ui->tblWomanPref->item(i,j);
            data = qit->text();
            womanPref[i][j] = data.toInt() - 1; //All the index are base 0
        }
    }

    //Execute the Algorithm.
    stringstream out;
    women = stableMatching(_size, manPref, womanPref, out);

    ui->txtLog->clear();
    ui->txtLog->setText(out.str().c_str());

    ui->tblMatch->clear();
    ui->tblMatch->setColumnWidth(0,100);
    listH << "Men Engagement";

    for(i =0; i<_size; i++)
    {
        stringstream out;
        stringstream aux;

        aux << "woman " << (i+1);
        listV << aux.str().c_str();

        out << (women[i]+1); //Add 1 cause indexes are base 0.
        QString data = out.str().c_str();
        QTableWidgetItem* it = new QTableWidgetItem();
        it->setText(data);
        ui->tblMatch->setItem(i, 0, it);
    }

    ui->tblMatch->setHorizontalHeaderLabels(listH);
    ui->tblMatch->setVerticalHeaderLabels(listV);

    delete[] women;
    for(i=0; i<_size; i++)
    {
        delete[] womanPref[i];
        delete[] manPref[i];
    }
    delete[] womanPref;
    delete[] manPref;

}


/**
 * @brief frmPerfectMatching::perfectMatching. This algoritm use a Stack instead of least to substract the firs element in one single step execution: O(1)
 * @param size      Size of Input by gender
 * @param manPref   A double array with Men's preferences.
 * @param womanPref A double array with Women's preferences.
 * @return An array in wich each item represent a woman and his final egagement.
 */
int* frmStableMatching::stableMatching(int size, int** manPref, int** womanPref, stringstream& steps)
{
    steps << "-------------- Begin Stable Matching Algorithm--------------" << endl;

    int stepCount = 0;
    int* womanEngagement = new int[size];
    int* nextOffer = new int[size];
    stack<int> singleMen;

    //Create the Stack of single men and initialize the auxiliary arrais.
    for(int i=size-1; i>=0; i--)
    {
        singleMen.push(i);
        nextOffer[i] = 0;
        womanEngagement[i] = -1;
     }

    while(singleMen.size() > 0) //While there is a single man.
    {
        int m = singleMen.top();            //O(1): Get the inmediaty free man.
        int wp = manPref[m][nextOffer[m]];  //O(1): Chose the next woman to offer.
        int cm = womanEngagement[wp];            //O(1): Get the Current Man in her list of preference of current woman.

        stepCount++;
        steps << "Step: (" << stepCount << ")" << endl;
        steps << "\tMan["<< (m + 1) << "] Offer to Woman [" << (wp + 1) << "] who is his Preference order list: " << (nextOffer[m] + 1) << endl;

        singleMen.pop(); //take out the first man of stak cause he is offering.
        nextOffer[m]++;

        //Evaluate the preferences of her for both candidates.
        int Poffer = womanPref[wp][m];
        int Pcurrent = -1;

        if(cm >=0)
            Pcurrent = womanPref[wp][cm];

        steps << "\tPreference Offer: [" << (Poffer+1) << "] VS Current Preference [" << (Pcurrent+1) << "]" << endl;

        if(Pcurrent == -1 || cm ==-1 || (Poffer < Pcurrent)) //If the woman has no engagement or the offer is greate than current (from 1 to n the prefreence)
        {
            if(cm > -1)
            {
                singleMen.push(cm); //The previous engagement Man is become free of engagement.
                steps << "\tWoman [" << (wp+1) << "] end engagement with man [" << (cm+1) << "] and become free" << endl;
            }
            womanEngagement[wp] = m; //Set the new engagement.
            steps << "\tWoman [" << (wp+1) << "] now is engagement with man [" << (m+1) << "]" << endl;
        }
        else
        {
            singleMen.push(m); //The Man who offers become free again.
            steps << "\tWoman [" << (wp+1) << "] denied offer of man [" << (m+1) << "]" << endl;
        }
    }

    delete[] nextOffer;

    steps << "--------------- End Stable Matching Algorithm ---------------" << endl;
    return womanEngagement;
}


