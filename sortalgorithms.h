#ifndef SORTALGORITHMS_H
#define SORTALGORITHMS_H

#include <vector>
#include <sstream>
#include <thread>
#include <future>
#include <atomic>
#include <vector>

#include "measuretool.h"

using namespace std;
using namespace std::chrono;

namespace sort
{

    template<class T>
    class Gnome
    {
        typedef typename std::vector<T>::iterator iterator;


    public:

        /*********************************
         * Gnome Sort = O(n^2)
         *********************************/
        void operator()(size_t size,
                        iterator begin,
                        iterator end,
                        std::stringstream& steps)
        {

            measure::MeasureTool tool;
            long comp{0}, mov{0};

            if(size <= 0 || begin == end)
            {
                steps << "There is no items to sort" << endl;
                return;
            }

            iterator arr = begin;

            high_resolution_clock::time_point tBegin = high_resolution_clock::now();

            size_t pos = 1;

            while(pos < size) //T(n-1)
            {
                comp++;
                if(arr[pos] < arr[pos-1] )
                {
                    size_t pos_i = pos;
                    while(pos_i > 0 && arr[pos_i] < arr[pos_i - 1]) // T(n-1)
                    {
                        comp++;
                        mov++;
                        T tmp = arr[pos_i];
                        arr[pos_i] = arr[pos_i - 1];
                        arr[pos_i-1] = tmp;
                        pos_i--;
                    }
                }
                pos++;
            }

            tool.measureTime(tBegin,steps);
            steps << "\t-:Total Comp: " << comp << "; Total Moves: " << mov << ":-" << endl;
        }
    };  //Gnome

    template<class T>
    class Insertion
    {
        typedef typename std::vector<T>::iterator iterator;
    public:


        /*********************************
         * Insertion Sort =O(n^2)
         *********************************/
        void operator()(size_t size,
                        iterator begin,
                        iterator end,
                        std::stringstream& steps)
        {

            measure::MeasureTool tool;
            long comp{0}, mov{0};

            if(size <= 0 || begin == end)
            {
                steps << "There is no items to sort" << endl;
                return;
            }

            high_resolution_clock::time_point tBegin = high_resolution_clock::now();

            for (size_t i=1; i < size; i++) // O(n-1)
            {
                int key = begin[i];
                int j = i-1;
                while(j >= 0 && key <= begin[j]) //O(m-1)
                {
                    begin[j+ 1] = begin[j];
                    j--;
                    comp++;
                    mov++;
                }
                begin[j + 1] = key;
            }

            tool.measureTime(tBegin,steps);
            steps << "\t-:Total Comp: " << comp << "; Total Moves: " << mov << ":-" << endl;
        }
    };  //Insertion

    template<class T>
    class Bubble
    {
        typedef typename std::vector<T>::iterator iterator;
    public:

        /*********************************
        * Buble Sort =O(n^2)
        *********************************/
        void operator()(size_t size,
                        iterator begin,
                        iterator end,
                        std::stringstream& steps)
        {
            iterator v = begin;

            if(size <=0 || begin == end)
            {
                steps << "There is no items to sort" << endl;
                return;
            }

            bool keepSorting;
            long comp{0}, mov{0};
            int limit{0};
            long itrs{0};

            high_resolution_clock::time_point tBegin = high_resolution_clock::now();
            measure::MeasureTool tool;

            do
            {
                keepSorting = false;
                limit = size - (1 + itrs);

                for(int i=0; i < limit; i++) //T(n-1-itrs)
                {
                    comp++;
                    if(v[i] > v[i+1])
                    {
                        int tmp = v[i+1];
                        v[i+1] = v[i];
                        v[i] = tmp;
                        keepSorting = true;
                        mov++;
                    }
                }
                itrs++;
            }while(keepSorting);                //  T(n-1)

            tool.measureTime(tBegin,steps);
            steps << "\t-:Total Comp: " << comp << "; Total Moves: " << mov << ":-"<< endl;
        }
    };  //Buble

    template<class T>
    class Selection {

        typedef typename std::vector<T>::iterator iterator;

    public:

        /*********************************
        * Selection Sort = O(n^2)
        *********************************/
        void operator()(size_t size,
                        iterator begin,
                        iterator end,
                        std::stringstream& steps)
        {
            long comp{0}, mov{0};
            iterator v = begin;

            if(size <=0 || begin == end)
            {
                steps << "There is no items to sort" << endl;
                return;
            }

            high_resolution_clock::time_point tBegin = high_resolution_clock::now();
            measure::MeasureTool tool;

            for(size_t i = 0; i < size; i++) //T(n)
            {
                size_t imin = i;
                for(size_t j = i+1; j < size; j++) //T(n-1)
                {
                    imin = v[j] < v[i] ? j : imin;
                    comp++;
                }

                //SWAP
                if(imin != i)
                {
                    T tmp = v[i];
                    v[i] = v[imin];
                    v[imin] = tmp;
                    mov++;
                }

            }

            tool.measureTime(tBegin,steps);
            steps << "\t-:Total Comp: " << comp << "; Total Moves: " << mov << ":-"<< endl;
        }

    };

    template<class T>
    class Merge
    {
        typedef typename std::vector<T>::iterator iterator;

        void mergeSort(size_t size,
                   iterator begin,
                   iterator end,
                   std::atomic<long>& comps, std::atomic<long>& moves,
                   std::atomic<long>& invkCnt, std::atomic<long>& maxDeep,
                   bool first=false, long deepInd =1)
        {
            invkCnt++;
            maxDeep = deepInd > maxDeep ? deepInd : (long)maxDeep;
            deepInd++;

            if(size <= 2)   //T(n)
            {
                if(size == 2 && begin[0] > begin[1])
                {
                    comps++;
                    moves++;
                    long tmp = begin[1];
                    begin[1] = begin[0];
                    begin[0] = tmp;
                }
            }
            else
            {
                size_t mdlsz = static_cast<size_t>(size / 2);
                int enL = mdlsz-1;

                if(first) //At first time, the algorithm create two threads to be executed concurrently
                {
                    std::thread t1([&]{
                        mergeSort(mdlsz, begin, begin + enL, comps, moves, invkCnt, maxDeep, false, deepInd); //Left T(n/2)
                    });
                    std::thread t2([&]{
                        mergeSort(size - mdlsz, begin + mdlsz,  end, comps, moves, invkCnt, maxDeep, false, deepInd); //Rigth T(n/2)
                    });

                    t1.join();
                    t2.join();
                }
                else //After the first time, the algorithm execute the alforithm over a secuential sequence
                {

                    mergeSort(mdlsz,        begin,          begin + enL, comps, moves, invkCnt, maxDeep, false, deepInd); //Left T(n/2)
                    mergeSort(size - mdlsz, begin + mdlsz,  end,         comps, moves, invkCnt, maxDeep, false, deepInd); //Rigth T(n/2)
                }

                merge(mdlsz, begin, size - mdlsz, begin + mdlsz, comps, moves); //Merge both T(2n)
            }
        }

        //Total Time T(2n)
        void merge(size_t lSize, iterator lBegin,
                   size_t rSize, iterator rBegin,
                   std::atomic<long>& comps, std::atomic<long>& movs)
        {
            size_t size = lSize + rSize;
            vector<int> temp(size);

            //long ltL{idxr}, ltR{idxl + size};
            size_t k{0}, l{0}, r{0};

            //1.- Sort in a temporary vector
            bool kL = l < lSize;
            bool kR = r < rSize;

            while(kL || kR )    //T(n/2 + n/2) = T(n)
            {
                if(kL && kR)
                    temp[k++] = lBegin[l] <= rBegin[r] ? lBegin[l++] : rBegin[r++];
                else
                    temp[k++] = kL ? lBegin[l++] : rBegin[r++];

                comps++;
                movs++;

                kL = l < lSize;
                kR = r < rSize;
            }

            //2.- Add them to the original vector
            for(k=0; k < size; k++)     //T(n)
            {
                movs++;
                lBegin[k] = temp[k];
            }
        }

    public:

        /**************
         * O(n log(n))
         *
         * Divide and conquer
         *
         * This algorith use tow thread to execute concurrently the firs division,
         * the subsequent divisions will be executed over a continuous sequence.
         **************/
        void operator()(size_t size,
                        iterator begin,
                        iterator end,
                        std::stringstream& steps)
        {
            measure::MeasureTool tool;

            std::atomic<long> comp{0};
            std::atomic<long> mov{0};
            std::atomic<long> invkCnt{0}, maxDeep{0};

            //long comp{0}, mov{0};

            if(size <=0 || begin == end)
            {
                steps << "There is no items to sort" << endl;
                return;
            }

            high_resolution_clock::time_point tBegin = high_resolution_clock::now();

            if(size > 1)
                mergeSort(size, begin, end, comp, mov, invkCnt, maxDeep, true);
            else
                steps << "There is no elementos to sort" << endl;
            tool.measureTime(tBegin,steps);

            steps << "\t-:Total Comp: " << comp << "; Total Moves: " << mov << ":-" << endl;
            steps << "\t-:Max Recursion Deep: " << maxDeep << ", Total times over Recursion Function invocation: " << invkCnt<< "" << endl;
        }
    };  //Merge

    template<class T>
    class Quick{
        typedef typename std::vector<T>::iterator iterator;

        /*
         * Storage complexity O(1); Its is unstable for a large mount of N.
         * Time complexity T(n)
         */
        /*
        size_t Partition(size_t size,
                       iterator begin,
                       std::atomic<long>& comp,
                       std::atomic<long>&mov)
        {

            iterator v = begin;
            size_t ipvt = size -1; //The pivot is the last item of the array.
            size_t i = 0;

            while(i < ipvt) //T(n)
            {
                if(v[i] >= v[ipvt])
                {
                    T tmp = v[i]; //O(1)
                    for(size_t j = i; j < ipvt; j++, mov++) v[j] = v[j+1];
                    v[ipvt] = tmp;
                    mov++;
                    ipvt--;
                }
                else
                    i++;
                comp++;
            }

            return ipvt; //return the new index of pivot;
        }
        */

        /*
         * Storage complexity O(n+1);
         * Time complexity T(2n)
         */
        /*
        size_t Partition(size_t size,
                       iterator arr,
                       std::atomic<long>& comp,
                       std::atomic<long>&mov)
        {
            size_t iLo{0}, iHi{size -1}; //The pivot is the last item of the array.

            std::vector<T> tmp(size); //O(n)
            T kv = arr[size-1];       //O(1)

            for(size_t i=0; i<size-1; i++) //T(n-1)
            {
                comp++;
                mov++;
                if(arr[i] >= kv)
                    tmp[iHi--] = arr[i];
                else
                    tmp[iLo++] = arr[i];
            }

            tmp[iHi] = kv;

            for(size_t i=0; i<size; i++) //T(n)
            {
                mov++;
                arr[i] = tmp[i];
            }

            return iHi; //return the new index of pivot;
        }
        */

        /*
         * Using the middle item as pivot.
         * Storage complexity O(n);
         * Time complexity T(3n/2)
         */
        size_t Partition(size_t size,
                       iterator arr,
                       std::atomic<long>& comp,
                       std::atomic<long>&mov)
        {
            size_t pvt{1};

            if(size == 2)
            {
                pvt = 1;
                comp++;
                if(arr[0] > arr[1])
                {
                    T v = arr[1];
                    arr[1] = arr[0];
                    arr[0] = v;
                    mov++;
                }
            }
            else if(size > 2)
            {
                std::vector<T> tmp(size); //O(n)

                pvt = (size_t)size/2;

                size_t iLo{0}, iHi{size -1};
                size_t iL{0}, iR{size -1};

                while(iL != pvt || iR != pvt) //T(n/2)
                {
                    if(iL != pvt)
                    {
                        comp++;
                        mov++;
                        if( arr[iL] >= arr[pvt])
                            tmp[iHi--] = arr[iL++];
                        else
                            tmp[iLo++] = arr[iL++];
                    }

                    if(iR != pvt)
                    {
                        comp++;
                        mov++;
                        if( arr[iR] >= arr[pvt])
                            tmp[iHi--] = arr[iR--];
                        else
                            tmp[iLo++] = arr[iR--];
                    }
                }

                tmp[iHi] = arr[pvt];
                pvt = iHi;

                for(size_t i=0; i<size; i++) //T(n)
                {
                    mov++;
                    arr[i] = tmp[i];
                }
            }


            return pvt; //return the new index of pivot;
        }


        void QuickSort(size_t size,
                       iterator begin,
                       iterator end,
                       std::atomic<long>& comp,
                       std::atomic<long>&mov,
                       std::atomic<long>& invkCnt,
                       std::atomic<long>& maxDeep,
                       bool first = false, long deepInd = 1)
        {
            invkCnt++;
            maxDeep = deepInd > maxDeep ? deepInd : (long)maxDeep;
            deepInd++;

            if(begin == end || size <= 1) return;

            size_t ipvt = Partition(size, begin, comp, mov);

            size_t sl = ipvt;
            size_t sr = size - (sl + 1);


            if(first)
            {
                std::thread t1 ([&]{
                                QuickSort(sl, begin, begin + ipvt, comp, mov, invkCnt, maxDeep, false, deepInd);
                            });

                std::thread t2 ([&]{
                                QuickSort(sr, begin + ipvt + 1, end, comp, mov, invkCnt, maxDeep, false, deepInd);
                            });

                t1.join();
                t2.join();
            }
            else
            {
                QuickSort(sl, begin, begin + ipvt, comp, mov, invkCnt, maxDeep, false, deepInd);
                QuickSort(sr, begin + ipvt + 1, end, comp, mov, invkCnt, maxDeep, false, deepInd);
            }
        }

    public:

        /*********************************
         * Quick Sort = O(n log(n))
         * input sample: 3 7 8 5 2 1 9 5 4
         *********************************/
        void operator()(size_t size,
                        iterator begin,
                        iterator end,
                        std::stringstream& steps)
        {

            measure::MeasureTool tool;
            std::atomic<long> comp{0}, mov{0};
            std::atomic<long> invkCnt{0}, maxDeep{0};

            if(size <= 0 || begin == end)
            {
                steps << "There is no items to sort" << endl;
                return;
            }

            high_resolution_clock::time_point tBegin = high_resolution_clock::now();

            QuickSort(size, begin, end, comp, mov, invkCnt, maxDeep, true);

            tool.measureTime(tBegin,steps);
            steps << "\t-:Total Comp: " << comp << "; Total Moves: " << mov << ":-" << endl;
            steps << "\t-:Max Recursion Deep: " << maxDeep << ", Total times over Recursion Function invocation: " << invkCnt<< "" << endl;

        }
    }; //Quick Sort

    template<class Item, class Algorithm=Insertion<Item>>
    void Sort(size_t size, Item begin, Item end, Algorithm algSort, std::stringstream& steps)
    {
        algSort(size, begin, end, steps);
    }

}//sort
#endif // SORTALGORITHMS_H
