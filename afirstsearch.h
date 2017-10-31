#ifndef AFIRSTSEARCH_H
#define AFIRSTSEARCH_H

#include "tnode.h"
#include <sstream>

using namespace std;

namespace algorithms
{
    class AFirstSearch
    {

        void DFS(int root, bool* explored, int* parents,
                 vector<TNode*> &G, vector<TNode*> &T,
                 stringstream &steps );
    public:
        AFirstSearch();

        void BFS(int root, vector<TNode*> &G, vector<TNode*> &T, stringstream &steps, bool checkBipartitenes=true);
        void DFS(int root, vector<TNode*> &G, vector<TNode*> &T, stringstream &steps);
        void checkDAG(vector<TNode*> &G, stringstream &steps);
    };
}

#endif // AFIRSTSEARCH_H
