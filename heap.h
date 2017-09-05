#ifndef HEAP_H
#define HEAP_H

#include<sstream>

#define HEAP_MAX_SIZE   524

using namespace std;

namespace collections {

/**
 * @brief The HeapItem class is used to be inherited by other classes which are the Final Item of priority queue.
 *
 * According with Heap Structure, each item must have a key value to be compare again each other.
 *
 */
class HeapItem
{
    long _key=0;
    int _heapPosition=-1;

public:

    HeapItem(){}
    HeapItem(long k){_key=k;}
    long getKey(){return _key;}
    void setKey(long k){_key=k;}
    void setHeapPosition(int i){_heapPosition=i;}
    int getHeapPosition(){return _heapPosition;}
    int getParent(){return (int)_heapPosition/2;}
};

/**
 * @brief The Heap class is the data structure.
 */
class Heap
{
    HeapItem* h_array[HEAP_MAX_SIZE];
    int lastItemPos;
    int _levels;

    void calculateLevels();

    void heapify_up(int position, stringstream& steps);
    void heapify_down(int position, stringstream& steps);



public:
    Heap();

    int size();
    int levels();

    HeapItem* operator[](int index);

    bool Insert(HeapItem* item, stringstream& steps);
    HeapItem* FindMin(stringstream& steps);

    HeapItem* ExtractMin(stringstream& steps);
    HeapItem* Delete(int index, stringstream& steps);
};


}//namespace

#endif // HEAP_H
