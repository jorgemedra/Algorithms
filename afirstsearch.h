#ifndef AFIRSTSEARCH_H
#define AFIRSTSEARCH_H

#include "tnode.h"
#include <sstream>

using namespace std;

namespace algorithms
{
    class AFirstSearch
    {

        void DFS(int root, bool* explored, int* parents, vector<TNode*> &G, vector<TNode*> &T, stringstream &steps );
    public:
        AFirstSearch();

        void BFS(int root, vector<TNode*> &G, vector<TNode*> &T, stringstream &steps);
        void DFS(int root, vector<TNode*> &G, vector<TNode*> &T, stringstream &steps);
    };
}

#endif // AFIRSTSEARCH_H
