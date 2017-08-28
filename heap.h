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
    long _key;
   public:
    long getKey(){return _key;}
    void setKey(long k){_key=k;}
};

/**
 * @brief The Heap class is the data structure.
 */
class Heap
{
    HeapItem* h_array[HEAP_MAX_SIZE];
    int lastItemPos;

    void heapify_up(int position, stringstream& steps);
    void heapify_down(int position, stringstream& steps);


public:
    Heap();

    int size();
    HeapItem* getItem(int index);

    bool Enqueue(HeapItem* item, stringstream& steps);
    HeapItem* Dequeue(stringstream& steps);
    HeapItem* Dequeue(int position, stringstream& steps);

};


}//namespace

#endif // HEAP_H
