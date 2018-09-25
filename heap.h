
#ifndef HEAP_H
#define HEAP_H

#include<sstream>
#include<vector>
#include <tuple>
#include <chrono>
#include <measuretool.h>

namespace collections {


const long HEAP_MAX_SIZE = 524;

/**
 * @brief The HeapItem class is used to be inherited by other classes which are the Final Item of priority queue.
 *
 * According with Heap Structure, each item must have a key value to be compare again each other.
 *
 */

template <class T>
class Heap
{
    std::vector<T> h_array;
    std::vector<long> k_array;

    size_t lastItemPos;
    size_t _levels;

    void calculateLevels();

    void heapify_up(size_t position, std::stringstream& steps);
    void heapify_down(size_t position, std::stringstream& steps);

    bool _orderByMin;

public:
    Heap(bool orderByMin = true):h_array{}, k_array{}, _orderByMin{orderByMin}{}

    bool isOrerderedbyMin();

    size_t size();
    size_t levels();

    T& operator[](size_t index);
    long Key(size_t index);

    bool Insert(long key, T item, std::stringstream& steps);
    T& FindMinMax(bool& success, std::stringstream& steps);
    T& ExtractMin(bool& success, std::stringstream& steps);
    T& Delete(size_t index, bool& success, std::stringstream& steps);
};

template <class T>
bool Heap<T>::isOrerderedbyMin()
{
    return _orderByMin;
}

template <class T>
size_t Heap<T>::size()
{
    return h_array.size();
}

template <class T>
size_t Heap<T>::levels()
{
    return _levels;
}

template <class T>
void Heap<T>::calculateLevels()
{
    size_t _size = size();
    _levels = 0;

    for(int i=1; i <= _size; i=i*2)
    {
        if(h_array.size() <= i) return;
        else _levels++;
    }
}

template <class T>
T& Heap<T>::operator[](size_t index)
{
    index--; //Index Array is base CERO.
    if(index < 0 || index >= this->size()) throw std::out_of_range("Heap<>::Index out of range.");

    return h_array[index];
}

template <class T>
long Heap<T>::Key(size_t index)
{
    index--; //Index Array is base CERO.
    if(index < 0 || index >= this->size()) throw std::out_of_range("Heap<>::Index out of range.");

    return k_array[index];
}

template <class T>
bool Heap<T>::Insert(long key, T item, std::stringstream& steps)
{
    measure::MeasureTool mt;
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    steps << "HEAP::Insert" << std::endl;
    if((size() + 1) > HEAP_MAX_SIZE)
    {
        steps << "\tError: The queue is full." << std::endl;
        return false;
    }

    h_array.push_back(item);
    k_array.push_back(key);

    steps << "\tThe Item was added int Pos:[" << size() << "]-Key: [" << key << "] " << std::endl;

    if(size()>0) heapify_up(size(), steps); //Redorder heap. This function requeres a index base 1.
    else         steps << "\tIt has been inserted at the first position." << std::endl;


    mt.measureTime(t1, steps);

    calculateLevels();
    return true;
}

/**
 * @brief Heap::FindMin find the minimun element of the priority queue.
 * @success& Boolean variable which recive the result of event.
 * @param steps
 * @return The firs element of the priority queue.
 */
template <class T>
T& Heap<T>::FindMinMax(bool& success, std::stringstream& steps)
{
    T itemEmpty;
    success = true;
    if(h_array.empty())
    {
        success = false;
        if(_orderByMin) steps << "HEAP::FindMin: There is no items into Heap." << std::endl;
        else steps << "HEAP::FindMax: There is no items into Heap." << std::endl;
        return itemEmpty;
    }

    try{
        return h_array[0];
    }catch(std::out_of_range)
    {
        success = false;
    }
    return itemEmpty;
}

/**
 *  Take out and return the firt item of the Heap, which has the lesser value.
 */
template <class T>
T& Heap<T>::ExtractMin(bool& success, std::stringstream& steps)
{
    T emptyItem;
    success = true;

    if(h_array.empty())
    {
        success = false;
        if(_orderByMin) steps << "HEAP::EXTRACTMIN: There is no items into Heap." << std::endl;
        else steps << "HEAP::EXTRACTMIN: There is no items into Heap." << std::endl;
        return emptyItem;
    }

    if(_orderByMin) steps << "HEAP::EXTRACTMIN" << std::endl;
    else steps << "HEAP::EXTRACTMAX" << std::endl;

    return Delete(1, success, steps);
}

/**
 * @brief Heap::Dequeue an item of the heap in specific position.
 * @param position The position of element in Base 1.
 * @param steps
 * @return the item that has been deleted.
 */
template <class T>
T& Heap<T>::Delete(size_t position, bool& success, std::stringstream& steps)
{
    T item;
    T parent;
    T itemSwaped;
    long key;
    long keyParent;
    long keyItemSwaped;
    measure::MeasureTool mt;

    success = false;

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    steps << "HEAP::DELETE[" << position << "]" << std::endl;

    if(position-1 < 0 || position-1 >= size())
    {
        steps << "\tError: Index out of range." << std::endl;
        return item;
    }

    item = h_array[position-1];
    key = k_array[position-1];

    if(h_array.size() == 1 || position-1 == (size()-1))
    {
        if(h_array.size()==1)
            steps << "\tIt was removed the last item." << std::endl;
        else
            steps << "\tIt was removed the unique item. The Heap is empty." << std::endl;

        h_array.pop_back();
        k_array.pop_back();
        calculateLevels();
        success = true;
        mt.measureTime(t1, steps);
        return item;
    }

    //Swap the las item to the removed item position and reduce the size of Heap.
    size_t lastItemPos = size()-1;
    itemSwaped = h_array[lastItemPos];
    keyItemSwaped = k_array[lastItemPos];

    h_array[position-1] = itemSwaped;
    k_array[position-1] = keyItemSwaped;

    h_array.pop_back();
    k_array.pop_back();

    steps << "\tItem [" << position << "] delete and Swaped by Item [" << size() << "]." << std::endl;

    if(position == 1)   //The first element do a Heapify-Down
    {
        heapify_down(position,steps); //Run heapify_down from root.
    }
    else
    {
        int posParent = (int)(position / 2);
        parent = h_array[posParent-1];
        keyParent = k_array[posParent-1];

        if(_orderByMin)
        {
            if(keyParent > keyItemSwaped)
                heapify_up(position, steps);
            else
                heapify_down(position, steps);
        }
        else
        {
            if(keyParent < keyItemSwaped)
                heapify_up(position, steps);
            else
                heapify_down(position, steps);
        }
    }

    mt.measureTime(t1, steps);
    calculateLevels();
    success = true;
    return item;
}

/**
 * @brief Heap::heapify_Up
 * @param position Index base 1, to apply the children relation Left=2(position) and Right = 2(position) +1
 * @param steps
 */
template <class T>
void Heap<T>::heapify_up(size_t position, std::stringstream& steps)
{
    T parent;
    T child;
    long kparent;
    long kchild;

    steps << "HEAP::Heapify-Up:" << std::endl;

    if(position > 1) //The item is not the root.
    {
        int posParent = (int)(position / 2); //Index Base Cero

        parent = h_array[posParent-1];  //Array Index Base Cero
        kparent = k_array[posParent-1];
        child = h_array[position-1];    //Array Index Base Cero
        kchild = k_array[position-1];

        if((_orderByMin && kchild < kparent) || (!_orderByMin && kchild > kparent))
        {
            steps << "\tSwap Item Parent I:[" << posParent << "]-K:(" << kparent << ") and "
                  << "Item Child I:[" << position << "]-K[" << kchild << "]." << std::endl;

            h_array[posParent-1] = child; // Child Become the new Parent
            k_array[posParent-1] = kchild; // Child Become the new Parent

            h_array[position-1] = parent; // Swap position of pater again new Item.
            k_array[position-1] = kparent; // Swap position of pater again new Item.

            heapify_up(posParent, steps); //Evalue the new parent.
        }

    }
    else
        steps << "\tEnds without any change in position:["<< position << "]" << std::endl;
}

/**
 * @brief Heap::heapify_down
 * @param position Index base 1, to apply the children relation Left=2(position) and Right = 2(position) +1
 * @param steps
 */
template <class T>
void Heap<T>::heapify_down(size_t position, std::stringstream& steps)
{
    T root;
    long kroot;

    steps << "HEAP::Heapify-Down:" << std::endl;

    int posParent = position;
    int left = 2 * position;
    int right = (2 * position) + 1;

    if(position >= 1 && position <= (lastItemPos+1))
    {
        int posSwap = -1;
        T lChild;
        long klChild;
        T rChild;
        long krChild;
        T sItem;
        long ksItem;

        root = h_array[posParent-1];
        kroot = k_array[posParent-1];
        lChild = h_array[left-1];
        klChild = k_array[left-1];
        rChild = h_array[right-1];
        krChild = k_array[left-1];

        if(rChild != nullptr || lChild != nullptr)
        {
            //Chose the Child wich has the less key.
            if(rChild != nullptr && rChild != nullptr)
            {
                if( (_orderByMin && krChild < klChild) || (!_orderByMin && krChild > klChild))
                {
                    posSwap = right;
                    sItem = rChild;
                    ksItem = krChild;
                }
                else
                {
                    posSwap = left;
                    sItem = lChild;
                    ksItem = klChild;
                }
            }
            else
            {
                if(rChild != nullptr)
                {
                    posSwap = right;
                    sItem = rChild;
                    ksItem = krChild;
                }
                else
                {
                    posSwap = left;
                    sItem = lChild;
                    ksItem = klChild;
                }
            }

            //Check is the Root is greate than SwapItem.
            if((_orderByMin && kroot > ksItem) || (!_orderByMin && kroot < ksItem))
            {
                steps << "\tSwap Item Parent I:[" << posParent << "]-K:(" << kroot << ") and "
                      << "Item Child I:[" << posSwap << "]-K[" << ksItem << "]." << std::endl;

                h_array[posParent-1] = sItem;
                k_array[posParent-1] = ksItem;
                h_array[posSwap-1] = root;
                k_array[posSwap-1] = kroot;

                heapify_down(posSwap, steps); //Reevaluete the heap from the last item swaped.
            }
        }
        else
        {
            steps << "\tThere is no childs to performence a Heapify-Down at position:["<< position << "]" << std::endl;
        }

    }
    else
        steps << "\tEnded becasue there is an index out of range with position:["<< position << "]" << std::endl;
}

}//namespace
#endif // HEAP_H
