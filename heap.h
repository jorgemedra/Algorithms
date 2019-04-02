
#ifndef HEAP_H
#define HEAP_H

#include<sstream>
#include<vector>
#include<unordered_map>
#include <tuple>
#include <chrono>
#include <measuretool.h>

#include <iostream>
#include <sstream>

namespace collections {


const size_t HEAP_MAX_SIZE = 1024;
const size_t HEAP_INIFITY_KEY = std::numeric_limits<size_t>::max();

/**
 * @brief The HeapItem class is used to be inherited by other classes which are the Final Item of priority queue.
 *
 * According with Heap Structure, each item must have a key value to be compare again each other.
 *
 */

template <class T>
class Heap
{
    //std::vector<size_t> _heap; //Array to handle the Heap.
    std::vector<double> _heap; //Array to handle the Heap.
    std::vector<T> _h_array; // Array to handle the Items T
    std::unordered_map<T, size_t> _map_position; //<Item, Current Position>

    //size_t _kCounter;

    //size_t _lastItemPos;
    size_t _levels;
    bool _orderByMin;

    //size_t createRetriveKey();

    void calculateLevels();

    void swap(size_t pos1, size_t pos2, std::stringstream& steps);
    void heapify_up(size_t position, std::stringstream& steps);
    void heapify_down(size_t position, std::stringstream& steps);
    void reorderHeapFrom(size_t position, std::stringstream& steps);

public:

    Heap(bool orderByMin = true):
        _heap{},
        _h_array{},
        _map_position{},
        //_pos_key{},
        _levels{0},
        _orderByMin{orderByMin}
        //_kCounter{0}
    {}

    bool isOrerderedbyMin();

    bool empty();
    size_t size();
    size_t levels();

    T& operator[](size_t position); //To get the Item according its Position.
    //T& operator[](std::string rKey); //To get the Item according its RetriveKey.
    size_t Position(T& item); //To Item's position according its RetriveKey.
    //std::vector<std::string> Keys(); //Retrive a vector with all Retrive Keys.
    double Weigth(size_t position);

    //bool Insert(size_t weight, T& item, std::stringstream& steps);
    bool Insert(double weight, T& item, std::stringstream& steps);
    T& FindFirst(bool& success, std::stringstream& steps);
    T& ExtractFirst(bool& success, std::stringstream& steps);
    T& Delete(size_t index, bool& success, std::stringstream& steps);
    void changeKey(size_t position, double newkey, std::stringstream& steps);
    void changeKey(T& item, double newkey, std::stringstream& steps);
};

template <class T>
bool Heap<T>::isOrerderedbyMin()
{
    return _orderByMin;
}

template <class T>
bool Heap<T>::empty()
{
    return _heap.empty();
}

template <class T>
size_t Heap<T>::size()
{
    return _heap.size();
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

    double temp = log2(_size);
    _levels =static_cast<size_t>(temp) +1;
}

/**
 * @brief Heap<T>::operator [] Operator to get the Item according its Position.
 * @param position  The position of the item into the heap.
 * @return A reference to the Item.
 */
template <class T>
T& Heap<T>::operator[](size_t position)
{
    position--; //Index Array is base CERO.
    if(position < 0 || position >= size()) throw std::out_of_range("Heap<>::Index out of range.");

    return _h_array[position];
}


/**
 * @brief Heap<T>::operator [] Operator to get the position's item by its Retrive Key
 * @param key The Item wich is linked to the position.
 * @return The item.
 * /
template <class T>
T& Heap<T>::operator[](std::string rKey) //To Item position according its RetriveKey.
{
    size_t position = Position(rKey);
    if(!position) throw std::out_of_range("Heap<>::There is no such Retreive Key.");

    return _h_array[position-1];
}*/

/**
 * @brief Heap<T>::position retrive the position of an Item according its Retreive Key.
 * @param rKey
 * @return The position of the element.
 */
template<class T>
size_t  Heap<T>::Position(T& item)
{
    auto it = _map_position.find(item);

    if(it == _map_position.end())
        return 0;

    return _map_position[item];
}

/**
 * @brief Heap<T>::keys Retrive a vector with allthe  Retrive Keys.
 * @return a vetor of keys of string
 * /
template <class T>
std::vector<std::string> Heap<T>::Keys()
{
    std::vector<std::string> keys;

    for( auto it = _map_position.begin(); it != _map_position.end(); it++)
        keys.push_back(it->first);
    return keys;
}
*/

/**
 * @brief Heap<T>::CostKey Gets the Key Cost of the item which is used by Heap to order its items.
 * @param position The position, in base 1.
 * @return The current Key Cost of the Item into the hea.
 */
template <class T>
double Heap<T>::Weigth(size_t position)
{
    position--; //Index Array is base CERO.
    if(position < 0 || position >= size()) throw std::out_of_range("Heap<>::Index out of range.");

    return _heap[position];
}


/**
 * @brief swap Method to swap two items of the heap.
 * @param from position from
 * @param pos2 position to
 * @param steps
 */
template <class T>
void Heap<T>::swap(size_t from, size_t to, std::stringstream& steps)
{
    size_t pi{from-1}, pf{to-1};

    T it1,it2;
    it1 = _h_array[pi];
    it2 = _h_array[pf];

    //Swap the keys and items
    std::swap(_heap[pi],_heap[pf]);
    std::swap(_h_array[pi],_h_array[pf]);

    //Update the Position in the heap of each item, into the map.
    _map_position[it1] = to;
    _map_position[it2] = from;

    steps << "\tSwap Item from Pos[" << from << "] to Pos:[" << to << "]." << std::endl;
}

/**
 * @brief Heap::heapify_Up
 * @param position Index base 1, to apply the children relation Left=2(position) and Right = 2(position) +1
 * @param steps
 */
template <class T>
void Heap<T>::heapify_up(size_t position, std::stringstream& steps)
{
    size_t kparent;
    size_t kcurrent;

    steps << "HEAP::Heapify-Up:" << std::endl;

    if(position > 1) //The item is not the root.
    {
        size_t posParent = (size_t)(position / 2); //Index Base Cero

        kparent  = _heap[posParent-1];
        kcurrent = _heap[position-1];

        if((_orderByMin && kcurrent <= kparent) || (!_orderByMin && kcurrent >= kparent))
        {
            swap(position, posParent, steps);
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
    size_t to;
    size_t kroot;
    size_t krChild;
    size_t klChild;
    bool bLeft{false}, bRigth{false};

    size_t lastItemPos = size();

    steps << "HEAP::Heapify-Down:" << std::endl;

    size_t posParent = position;
    size_t left = 2 * position;
    size_t right = (2 * position) + 1;

    if(position >= 1 && position <= lastItemPos)
    {
        kroot = _heap[posParent-1];

        if(left <= lastItemPos) //There is a Left Child
        {
            klChild = _heap[left-1]; //Get key in heap
            bLeft   = (_orderByMin && klChild < kroot) || (!_orderByMin && klChild > kroot) ? true : false;
        }

        if(right <= lastItemPos) //There is a Left Child
        {
            krChild = _heap[right-1]; //Get key in heap
            bRigth  = (_orderByMin && krChild < kroot) || (!_orderByMin && krChild > kroot) ? true : false;
        }

        if(bLeft && bRigth)
        {
            bLeft = (_orderByMin && klChild < krChild) || (!_orderByMin && klChild > krChild) ? true :false;
            bRigth = !bLeft;
        }

        if(bLeft || bRigth)
        {
            to = bLeft ? left: right;
            swap(position, to, steps);
            heapify_down(to, steps);
        }
        else
            steps << "\tThere is no childs to performence a Heapify-Down at position:["<< position << "]" << std::endl;
    }
    else
        steps << "\tEnded due to there is an index out of range with position:["<< position << "]" << std::endl;
}

template <class T>
//bool Heap<T>::Insert(size_t weight, T& item, std::stringstream& steps)
bool Heap<T>::Insert(double weight, T& item, std::stringstream& steps)
{

    measure::MeasureTool mt;
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    //std::cout << "Insert H Address: [" << item <<  "]" << std::endl;

    steps << "HEAP::Insert" << std::endl;
    if((size() + 1) > HEAP_MAX_SIZE)
    {
        steps << "\tError: The queue is full." << std::endl;
        return false;
    }

    _heap.push_back(weight); //Store the Heap Key, which defines its order into the heap.
    _h_array.push_back(item); //Store in the same position of the Key the Item.
    //_pos_key.push_back(rtvKey); //Store the Retrive Key according its position.
    _map_position[item] = size(); //Link the Item to its current position into the heap.


    steps << "\tThe Item was added int Pos:[" << size() << "]-Weigth(): [" << weight << "] " << std::endl;

    if(size()>0) heapify_up(size(), steps); //Redorder heap. This function requeres a index base 1.
    else         steps << "\tIt has been inserted at the first position." << std::endl;


    mt.measureTime(t1, steps);

    calculateLevels();
    return true; //return the Retrive Key.
}

/**
 * @brief Heap::FindMin find the minimun element of the priority queue.
 * @success& Boolean variable which recive the result of event.
 * @param steps
 * @return The firs element of the priority queue.
 */
template <class T>
T& Heap<T>::FindFirst(bool& success, std::stringstream& steps)
{
    T itemEmpty;
    success = true;
    if(_h_array.empty())
    {
        success = false;
        if(_orderByMin) steps << "HEAP::FindMin: There is no items into Heap." << std::endl;
        else steps << "HEAP::FindMax: There is no items into Heap." << std::endl;
        return itemEmpty;
    }

    try{
        return _h_array[0];
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
T& Heap<T>::ExtractFirst(bool& success, std::stringstream& steps)
{
    T emptyItem;
    success = true;

    if(_heap.empty())
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
    size_t posLast = size();
    success = false;

    steps << "HEAP::DELETE[" << position << "]" << std::endl;

    measure::MeasureTool mt;
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    if(position < 1 || position > size())
    {
        T empty;
        steps << "\tError: Index out of range." << std::endl;
        return empty;
    }

    T top = _h_array[position-1];
    if(_heap.size()>1)
    {
        swap(position,posLast,steps); //Change them last Item vs the Top Item.
    }

    _map_position.erase(top); //remove the element from unorder_map
    _heap.erase(_heap.begin()+(posLast-1)); //remove the element from the last item of vector
    _h_array.erase(_h_array.begin()+(posLast-1));

    if(_h_array.size()>0)
        reorderHeapFrom(position,steps);

    mt.measureTime(t1, steps);
    calculateLevels();

    success = true;
    return top;
}

/**
 * @brief changeKey Method to change the key from a position.
 * @param position Position which has the key to change.
 * @param newkey The new key.
 * @param steps
 */
template <class T>
void Heap<T>::changeKey(size_t position, double newkey, std::stringstream& steps)
{

    measure::MeasureTool mt;
    steps << "HEAP::CHANGING KEY FROM POSITION:[" << position << "] TO:[" << newkey << "]" << std::endl;

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    if(position < 1 || position > size())
    {
        steps << "\tError: Index out of range." << std::endl;
        return;
    }

    _heap[position-1] = newkey;
    reorderHeapFrom(position,steps);
    mt.measureTime(t1, steps);
}

template <class T>
void Heap<T>::changeKey(T& item, double newkey, std::stringstream& steps)
{
    measure::MeasureTool mt;

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    size_t position = Position(item);

    if(position < 1 || position > size())
    {
        steps << "\tError: Index out of range." << std::endl;
        return;
    }

    steps << "HEAP::CHANGING KEY FROM POSITION:[" << position << "] TO:[" << newkey << "]" << std::endl;

    _heap[position-1] = newkey;
    reorderHeapFrom(position,steps);
    mt.measureTime(t1, steps);
}

/**
 * @brief Heap<T>::reorderHeapFrom
 * @param position The position of element in Base 1.
 * @param steps
 */
template <class T>
void Heap<T>::reorderHeapFrom(size_t position, std::stringstream& steps)
{
    size_t lastPos = size();

    if(position <= 0 && position > lastPos) return;

    if(position == 1)
        heapify_down(position,steps);
    else if(position == lastPos)
        heapify_up(position,steps);
    else
    {
        size_t posParent = (size_t)(position / 2);

        if( (_orderByMin && _heap[position-1] < _heap[posParent-1]) ||
                (!_orderByMin && _heap[position-1] > _heap[posParent-1]))
            heapify_up(position,steps);
        else
            heapify_down(position,steps);
    }

}


}//namespace
#endif // HEAP_H
