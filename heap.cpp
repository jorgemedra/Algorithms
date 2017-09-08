#include<cstdlib>
#include<iostream>
#include<sstream>

#include"heap.h"

using namespace std;
using namespace collections;

Heap::Heap()
{
    for(int i=0; i < HEAP_MAX_SIZE; i++)
        h_array[i] = nullptr;

    lastItemPos = -1;
}

int Heap::size()
{
    return (lastItemPos + 1);
}

int Heap::levels()
{
    return _levels;
}

void Heap::calculateLevels()
{
    int _size = lastItemPos + 1;
    _levels = 0;

    for(int i=1; i <= _size; i=i*2)
    {
        if(h_array[i-1]==nullptr) return;
        else _levels++;
    }
}

HeapItem* Heap::operator[](int index)
{
    index--; //Index Array is base CERO.
    if(index < 0 || index >= HEAP_MAX_SIZE) return nullptr;

    return h_array[index];
}

/**
 * @brief Heap::Insert a new item int the queue and sort it.
 * @param item Item to be inserted into the queue.
 * @param steps
 * @return
 */
bool Heap::Insert(HeapItem* item, stringstream& steps)
{
    steps << "HEAP::Insert" << endl;
    if((lastItemPos + 1) >= HEAP_MAX_SIZE || item == nullptr)
    {
        steps << "\tError: The queue is full or the item is NULL" << endl;
        return false;
    }

    lastItemPos++;
    h_array[lastItemPos] = item;
    steps << "\tThe Item was added int Pos:[" << (lastItemPos+1) << "]-Key: [" << item->getKey() << "] " << endl;

    if(lastItemPos>0)
        heapify_up(lastItemPos + 1, steps); //Redorder heap. This function requeres a index base 1.
    else
        steps << "\tIt has been inserted at the first position." << endl;

    calculateLevels();
    return true;
}

/**
 * @brief Heap::FindMin
 * @param steps
 * @return
 */
HeapItem* Heap::FindMin(stringstream& steps)
{
    if(lastItemPos <0)
    {
        steps << "HEAP::FindMin: There is no items into Heap." << endl;
        return nullptr;
    }

    return h_array[0];
}


/**
 *  Take out and return the firt item of the Heap, which has the lesser value.
 */
HeapItem* Heap::ExtractMin(stringstream& steps)
{
    steps << "HEAP::EXTRACTMIN" << endl;
    return Delete(1, steps);
}

/**
 * @brief Heap::Dequeue an item of the heap in specific position.
 * @param position The position of element in Base 1.
 * @param steps
 * @return
 */
HeapItem* Heap::Delete(int position, stringstream& steps)
{
    HeapItem* item = nullptr;
    HeapItem* parent = nullptr;
    HeapItem* itemSwaped = nullptr;

    steps << "HEAP::DELETE[" << position << "]" << endl;

    if(position < 1 || position > HEAP_MAX_SIZE)
    {
        steps << "\tError: Index out of range." << endl;
        return item;
    }

    item = h_array[position-1];//Get the item to remove and return.
    h_array[position-1] = nullptr;

    if(lastItemPos == 0) //there was just one Item.
    {
        lastItemPos--;
        steps << "\tIt was removed the unique item. The Heap is empty." << endl;
        calculateLevels();
        return item;
    }
    else if(lastItemPos == (position-1)) //The Item removed was the Last of array.
    {
        lastItemPos--;
        steps << "\tIt was removed the last item." << endl;
        calculateLevels();
        return item;
    }

    //Swap the las item to the removed item position and reduce the size of Heap.
    itemSwaped = h_array[lastItemPos];
    h_array[lastItemPos] = nullptr;
    h_array[position-1] = itemSwaped;
    lastItemPos--;

    steps << "\tItem [" << position << "] delete and Swaped by Item [" << (lastItemPos+1) << "]." << endl;

    if(position == 1)   //The first element do a Heapify-Down
    {
        heapify_down(position,steps); //Run heapify_down from root.
    }
    else
    {
        int posParent = (int)(position / 2);
        parent = h_array[posParent-1];

        if(parent->getKey() > itemSwaped->getKey())
            heapify_up(position,steps);
        else
            heapify_down(position,steps);
    }

    calculateLevels();
    return item;
}


/**
 * @brief Heap::heapify_Up
 * @param position In Base 1, to apply the children relation Left=2(position) and Right = 2(position) +1
 * @param steps
 */
void Heap::heapify_up(int position, stringstream& steps)
{
    HeapItem* parent=nullptr;
    HeapItem* child=nullptr;

    steps << "HEAP::Heapify-Up:" << endl;

    if(position > 1) //The item is not the root.
    {
        int posParent = (int)(position / 2); //Index Base Cero

        parent = h_array[posParent-1];  //Array Index Base Cero
        child = h_array[position-1];    //Array Index Base Cero


        if(child->getKey() < parent->getKey())
        {
            steps << "\tSwap Item Parent I:[" << posParent << "]-K:(" << parent->getKey() << ") and "
                  << "Item Child I:[" << position << "]-K[" << child->getKey() << "]." << endl;

            h_array[posParent-1] = child; // Child Become the new Parent
            h_array[position-1] = parent; // Swap position of pater again new Item.

            heapify_up(posParent, steps); //Evalue the new parent.
        }

    }
    else
        steps << "\tEnds without any change in position:["<< position << "]" << endl;
}

void Heap::heapify_down(int position, stringstream& steps)
{
    HeapItem* root=nullptr;

    steps << "HEAP::Heapify-Down:" << endl;

    int posParent = position;
    int left = 2 * position;
    int right = (2 * position) + 1;

    if(position >= 1 && position <= (lastItemPos+1))
    {
        int posSwap = -1;
        HeapItem* lChild=nullptr;
        HeapItem* rChild=nullptr;
        HeapItem* sItem=nullptr;


        root = h_array[posParent-1];
        lChild = h_array[left-1];
        rChild = h_array[right-1];


        if(rChild != nullptr || lChild != nullptr)
        {
            //Chose the Child wich has the less key.
            if(rChild != nullptr && rChild != nullptr)
            {
                if(rChild->getKey()  < lChild->getKey())
                {
                    posSwap = right;
                    sItem = rChild;
                }
                else
                {
                    posSwap = left;
                    sItem = lChild;
                }
            }
            else
            {
                if(rChild != nullptr)
                {
                    posSwap = right;
                    sItem = rChild;
                }
                else
                {
                    posSwap = left;
                    sItem = lChild;
                }
            }

            //Check is the Root is greate than SwapItem.
            if(root->getKey() > sItem->getKey())
            {
                steps << "\tSwap Item Parent I:[" << posParent << "]-K:(" << root->getKey() << ") and "
                      << "Item Child I:[" << posSwap << "]-K[" << sItem->getKey() << "]." << endl;

                h_array[posParent-1] = sItem;
                h_array[posSwap-1] = root;

                heapify_down(posSwap, steps); //Reevaluete the heap from the last item swaped.
            }
        }
        else
        {
            steps << "\tThere is no childs to performence a Heapify-Down at position:["<< position << "]" << endl;
        }

    }
    else
        steps << "\tEnded becasue there is an index out of range with position:["<< position << "]" << endl;
}
