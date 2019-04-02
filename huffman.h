#ifndef HUFFMAN_H
#define HUFFMAN_H

#include<QObject>
#include<vector>
#include<queue>
#include<string>
#include<fstream>
#include<unordered_map>

namespace huffman
{

const size_t MAX_CODE_SIZE = 32;

struct Symbol{
    size_t amount;
    double freq;
    char32_t code;
    std::string s_code;
    char symbol;
    unsigned char length;
    bool discovered;
    //Symbol():amount{0},freq{0},code{0x00},symbol{0x00},length{0x00},discovered{false}{}
    Symbol():amount{0},freq{0},code{0x00},s_code{""},symbol{0x00},length{0x00},discovered{false}{}
};

struct Node{
    double key;
    short curpos;
    short parent;
    short left;
    short rigth;
    bool leaf;
    char symbol;

    Node():key{0},parent{-1},left{-1},rigth{-1},leaf{false},symbol{0x00}{}
};

enum ProgressType : int
{
    flwScanning = 0,
    flwBuildingPTree,
    flwBuildingTSymbol,
    flwCompress,
    flwUncompress
};

class ProgressNotify: public QObject
{
    Q_OBJECT

signals:
    void siglProgress(int type, double percent);
    void sgnlLog(QString message);

public:
    ProgressNotify(){}

    void notifyProgress(ProgressType type, double percent){ emit siglProgress(type,percent); }
    void notifyLog(std::string message){ emit sgnlLog(QString(message.c_str())); }

};

class CodecTable{
    std::vector<Symbol> S;
    std::vector<Node> tree;
    short _root;
    size_t size;

    short addNode(char symbol, double k, bool leaf);
    void buildTable(size_t curpos, size_t deep, std::string s_code, ProgressNotify& notifier, bool isLeft = true);

public:
    CodecTable();
    ~CodecTable();

    bool build(std::string path, ProgressNotify& notifier);
    short Root();
    const Symbol operator()(int symbol);
    const Node operator[](int index);
};

    namespace tool
    {

        //void getChainOfBits(char32_t code, unsigned char lenght, std::vector<char>& buff, short& bits_reminded);
        void getChainOfBits(std::string code, std::vector<char>& buff, short& bits_reminded);
        unsigned char getByte(CodecTable& codec, std::ifstream& file, int& curByte, int& curBut);

        bool Compress   (CodecTable& codec, std::string path, std::string outpath, ProgressNotify& notifier);
        bool Uncompress (CodecTable& codec, std::string path, std::string outpath, ProgressNotify& notifier);

    }//tool

} //compress

#endif // HUFFMAN_H
