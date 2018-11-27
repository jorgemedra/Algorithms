#ifndef AFIRSTSEARCH_H
#define AFIRSTSEARCH_H

//#include "tnode.h"
#include"graphs.h"
#include <sstream>
#include <queue>

//using namespace std;

namespace algorithms
{
    class AFirstSearch
    {

        void DFS(long root, std::vector<short>& explored,
                 std::vector<int>& parents,
                 graphs::Graph &T,
                 std::stringstream &steps );

        bool checkDAG(graphs::Graph &G, std::queue<long>& topologic , std::stringstream &steps);

    public:
        AFirstSearch();

        void BFS(long root, graphs::Graph &T, std::stringstream &steps, bool checkBipartitenes=true);
        void DFS(long root, graphs::Graph &T, std::stringstream &steps);

        void checkDAG(graphs::Graph &G, std::stringstream &steps);

    };
}

#endif // AFIRSTSEARCH_H
