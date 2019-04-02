#include"huffman.h"
#include"heap.h"

#include <fstream>
#include <bitset>
#include<queue>
#include<iomanip>

using namespace huffman;
using namespace std;

CodecTable::CodecTable():S{},tree{},_root{-1},size{0}{
    S.resize(256);
}

CodecTable::~CodecTable()
{
    S.clear();
    tree.clear();
    cout << "~CodecTable" << endl;
}

short CodecTable::addNode(char symbol, double k, bool leaf)
{
    Node n;
    n.key = k;
    n.symbol = symbol;
    n.curpos = tree.size();
    n.leaf = leaf;
    tree.push_back(n);
    return n.curpos;
}

void CodecTable::buildTable(size_t curpos, size_t deep, string s_code, ProgressNotify& notifier, bool isLeft)
{
    if(deep > 0) s_code += isLeft ? "0" : "1";
    if(tree[curpos].leaf)
    {
        size_t index = (unsigned char)tree[curpos].symbol;
        S[index].length = deep;
        //S[index].code = code;
        S[index].s_code = s_code;

        stringstream out;
        out <<"Byte[" << index << "]: Bit Code: [" << S[index].s_code << "]" << endl;
        notifier.notifyLog(out.str());
    }
    else
    {
        buildTable(tree[curpos].left,deep + 1 , s_code, notifier,true);
        buildTable(tree[curpos].rigth,deep + 1, s_code, notifier,false);
    }
}

short CodecTable::Root()
{
    return _root;
}

const Symbol CodecTable::operator()(int symbol)
{
    return S[symbol];
}

const Node CodecTable::operator[](int index)
{
    return tree[index];
}

bool CodecTable::build(std::string path, ProgressNotify& notifier)
{
    stringstream temp;
    ifstream file;
    size_t nSize{0};
    bool success{false};

    file.open(path,ios::binary| ios::in);

    if(!file.is_open()) return false;

    file.seekg(0,ios::end);
    streamsize fSize = file.tellg();
    file.seekg(0,ios::beg);

    //Scans the file and gets the occurence of each byte.
    size = 0;
    notifier.notifyLog("Starting Scanning...");
    while(!file.eof())  //T(n).
    {
        char c;
        file.read(&c,1);
        nSize++;

        short index = ((unsigned char)c);
        if(!S[index].discovered)
        {
            //cout << "Discovered:[" << c << "]" << endl;
            S[index].symbol = c;
            S[index].discovered = true;
            size++;
        }

        S[index].amount++;

        double per = static_cast<double>(nSize) / static_cast<double>(fSize);
        notifier.notifyProgress(ProgressType::flwScanning, per);
    }

    file.close();
    notifier.notifyLog("Finish Scanning.");
    notifier.notifyProgress(ProgressType::flwScanning, static_cast<double>(100) );

    //Build the priority queue.
    collections::Heap<short> pqueue;
    notifier.notifyLog("Starting Building Tree...");
    for(int i=0; i<256; i++) //O(c log(c)); c = 256.
    {
        if(S[i].discovered)
        {
            temp.str("");
            S[i].freq = (double)S[i].amount / (double)nSize;
            short curpos = addNode(S[i].symbol, S[i].amount,true); //Add a leaf node.
            pqueue.Insert(tree[curpos].key, curpos, temp);
        }
    }

    //Build the tree
    size_t sizePq{pqueue.size()};
    size_t counter{0};
    while(pqueue.size() > 1)
    {
        temp.str("");
        short lPos = pqueue.ExtractFirst(success,temp);
        short rPos = pqueue.ExtractFirst(success,temp);

        double key = tree[lPos].key + tree[rPos].key;

        short curpos = addNode(0x00, key, false); //Add a parent  Node

        tree[curpos].rigth = lPos;
        tree[curpos].left = rPos;

        tree[lPos].parent = curpos;
        tree[rPos].parent = curpos;

        pqueue.Insert(key, curpos, temp);

        counter++;
        double per = static_cast<double>(counter) / static_cast<double>(sizePq);
        notifier.notifyProgress(ProgressType::flwBuildingPTree, per);
    }


    temp.str("");
    _root = pqueue.ExtractFirst(success,temp);
    buildTable(_root, 0, "", notifier);

    double tFrec = 0;
    double avgBits =0;
    for(size_t i=0; i<256; i++) //O(c log(c)); c = 256.
    {
        if(S[i].discovered)
        {
            tFrec += S[i].freq;
            avgBits +=  tFrec * S[i].amount;
            //cout << "Symbol [" << i << "](" << S[i].amount << "): Len(" << S[i].s_code.length();
            //cout << "):\t[" << S[i].s_code << "]" << endl;
        }
    }
    notifier.notifyLog("Finish Buidl Tree");
    temp.str("");
    temp << "Total Freq:" << tFrec;
    notifier.notifyLog(temp.str());

    return true;
}

void tool::getChainOfBits(std::string code, vector<char>& buff, short& bits_reminded)
{
    int size = code.length();//static_cast<int>(lenght);
    unsigned char BMASK=0x01;

    BMASK <<= bits_reminded-1; //Restor the mask at the last position according to the last byte.

    int iByte = 0;

    for(int i = 0; i < size; i++) //Por cada bit de la mascara
    {
        buff[iByte] |= code[i] == '1'? BMASK : 0x00;
        bits_reminded--;

        if(bits_reminded == 0)
        {
            buff.push_back(0x00); //add a new byte to the sequence
            iByte++;
            BMASK = 0x80;
            bits_reminded = 8;
        }
        else
            BMASK >>= 1;
    }
}

unsigned char tool::getByte(CodecTable& codec, ifstream& file, int& curByte, int& curBit)
{
    char c;
    file.seekg(curByte);
    file.read(&c,1);

    unsigned char mask = 0x01;
    mask <<= (curBit-1);

    int curNode = codec.Root();

    while(!codec[curNode].leaf)
    {
        //curNode = code[curBit] == '0' ? codec[curNode].left : codec[curNode].rigth;
        curNode = (mask & c) == 0x00 ? codec[curNode].left : codec[curNode].rigth;
        curBit--;

        if(curBit == 0)
        {
            file.read(&c,1);
            curByte++;
            curBit = 8;
            mask = 0x80;
            //mask >>= (8-curBit);
        }
        else
            mask >>= 1;
    }

    char ucc = codec[curNode].symbol;

    //file.seekg(ucc);
    return ucc;
}

bool tool::Compress(CodecTable& codec, std::string path, std::string outpath, ProgressNotify& notifier)
{
    ifstream file;
    ofstream ofile;
    stringstream out;

    out << "Starting to compress file: " << path << endl
        << "To file: " << outpath;
    notifier.notifyLog(out.str());

    file.open(path, ios::binary | ios::in);
    ofile.open(outpath, ios::binary | ios::out);

    if(!file.is_open() || !ofile.is_open() ) return false;

    char c;
    short bits_reminded{8};
    size_t amoutData = 0;

    char lastChar{0x00};
    vector<char> buffer(1,lastChar);

    file.seekg(0,ios::end);
    streamsize fsize = file.tellg();

    out.str("");
    out << "Sourece file with [" << fsize << "] Bytes.";
    notifier.notifyLog(out.str());

    if(fsize == 0)
    {
        file.close();
        ofile.close();
        return false;
    }

    double per{0};
    notifier.notifyProgress(ProgressType::flwCompress, per);

    file.seekg(0);
    double counter{0};
    while(!file.eof())  //T(n).
    {
        file.read(&c,1);
        counter++;
        int index = (unsigned char) c;

        getChainOfBits(codec(index).s_code, buffer,bits_reminded);
        amoutData = buffer.size();

        if(amoutData > 1)
        {
            char* ptr = buffer.data();
            ofile.write((const char*)ptr, amoutData-1);
        }

        if(bits_reminded == 8) amoutData--;
        lastChar = bits_reminded < 8 ? buffer[amoutData-1] : 0x00;
        buffer.resize(1);
        buffer[0]=lastChar;

        per =  counter/fsize;
        notifier.notifyProgress(ProgressType::flwCompress, per);
    }

    //Write the remain data
    if(bits_reminded != 8)
    {
        //cout << "Saving last byte" << endl;
        char* ptr = buffer.data();
        ofile.write((const char*)ptr, 1);
    }

    notifier.notifyProgress(ProgressType::flwCompress, 100);

    //Todo: Add one last byte with the amount of reminder Bits.
    ofile.write((const char*)&bits_reminded, 1);

    out.str("");
    out << "Saving remindeng bits["<< bitset<8>(bits_reminded) << "]";
    notifier.notifyLog(out.str());


    file.close();
    ofile.close();

    return true;
}

bool tool::Uncompress (CodecTable& codec, std::string path, std::string outpath, ProgressNotify& notifier)
{
    stringstream out;
    ifstream file;
    ofstream ofile;

    out << "Starting to uncompress file: " << path << endl
        << "To file: " << outpath;
    notifier.notifyLog(out.str());

    file.open(path, ios::binary | ios::in);
    ofile.open(outpath, ios::binary | ios::out);

    if(!file.is_open() || !ofile.is_open() )
    {
        cout << "Failed to open the file of reading or destiny" << endl;
        return false;
    }

    char c{0x00};
    unsigned char remaindBits{0x00};

    file.seekg(0,ios::end);
    streamsize fsize = file.tellg();

    if(fsize == 0)
    {
        file.close();
        ofile.close();
        return false;
    }

    file.seekg(fsize-1);
    file.read(&c,1);
    remaindBits = static_cast<unsigned char>(c);

    int curPos = 0;
    int curBit = 8;
    c = 0x00;
    fsize--;

    //cout << endl;
    notifier.notifyProgress(ProgressType::flwUncompress, 0);
    while(curPos < fsize)  //T(n).
    {
        char uChar = uChar = getByte(codec, file, curPos, curBit);

        //cout << '\r'
        //     << std::setw(6) << ((double)curPos / (double)fsize)*100 << "%             "
        //     << std::flush;

        if(curPos == fsize-1 && curBit  == remaindBits)
            break;

        double per =  static_cast<double>(curPos)/static_cast<double>(fsize);
        notifier.notifyProgress(ProgressType::flwUncompress, per);

        ofile.write(&uChar,1);
    }

    notifier.notifyProgress(ProgressType::flwUncompress, 100);

    file.close();
    ofile.close();

    out.str("");
    out << "Uncompress succesfull.";
    notifier.notifyLog(out.str());

    return true;
}


