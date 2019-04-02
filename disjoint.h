#ifndef DISJOINT_H
#define DISJOINT_H

#include<string>
#include<vector>
#include<unordered_map>

namespace collections
{

template <class T>
class Disjoint_Set
{
    /*
    struct Item
    {
        //size_t ID{0};
        //size_t Size{1};
        size_t Parent{0};
    };
    */

    std::vector<size_t> parents; //Vector to store the index of the parent.
    std::unordered_map<T,size_t> r_it; //map to hadle the relation of Item vs Index Position into the vector parents;

    size_t find_rec(size_t pos);

public:
    void MakeUnionFind(std::vector<T> s); //An order from 0 to N
    long Find(T);
    long Union(long,long);
};

template <class T>
void Disjoint_Set<T>::MakeUnionFind(std::vector<T> s)
{
    if(s.size() == 0) return;

    parents.resize(s.size());
    for(size_t inx = 0; inx < s.size(); inx++) //T(n)
    {
        parents[inx] = inx; //At the begin all the items has its parent as itself

        T key = s[inx];
        r_it.insert(std::make_pair(key,inx)); //This map link the Item to its index into the parents vector.
        //r_it[s[inx]] = inx;
    }
}

template <typename T>
size_t Disjoint_Set<T>::find_rec(size_t index)
{
    if( index == parents[index])
        return index;

    //Compress the path;
    size_t parent = find_rec(parents[index]);
    parents[index] = parent;

    return parent;
}

template <typename T>
long Disjoint_Set<T>::Find(T u)
{
    //std::unordered_map<T,size_t>::iterator it;
    auto it = r_it.find(u);

    if(it == r_it.end()) return -1;

    size_t post_itm = r_it[u];

    return static_cast<long>(find_rec(post_itm)); //O(log(n))
}

template <typename T>
long Disjoint_Set<T>::Union(long u, long v)
{
    long s = parents.size();

    if((u < 0 && u >= s) || (v < 0 && v >= s)) return -1; //Index out of range
    else if(u == v) return -2; //The items are already linked

    parents[u] = static_cast<size_t>(v);
    return v;
}

} //collections

#endif // DISJOINT_H
