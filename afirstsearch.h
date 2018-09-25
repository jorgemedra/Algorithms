#ifndef AFIRSTSEARCH_H
#define AFIRSTSEARCH_H

//#include "tnode.h"
#include "graphs.h"
#include <sstream>

//using namespace std;

namespace algorithms
{
    class AFirstSearch
    {

        void DFS(int root, std::vector<short>& explored,
                 std::vector<int>& parents,
                 algorithms::graphs::Graph &G,
                 algorithms::graphs::Graph &T,
                 std::stringstream &steps );
    public:
        AFirstSearch();

        void BFS(int root, algorithms::graphs::Graph &G,
                           algorithms::graphs::Graph &T,
                 std::stringstream &steps, bool checkBipartitenes=true);
        void DFS(int root, algorithms::graphs::Graph &G,
                           algorithms::graphs::Graph &T,
                 std::stringstream &steps);

        void checkDAG(algorithms::graphs::Graph &G, std::stringstream &steps);
    };
}

#endif // AFIRSTSEARCH_H
