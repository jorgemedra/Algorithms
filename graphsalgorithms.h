#ifndef AFIRSTSEARCH_H
#define AFIRSTSEARCH_H

#include"graphs.h"
#include <sstream>
#include <queue>
#include<stack>

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

    bool checkDAG(graphs::Graph &G, std::stringstream &steps);

};

namespace shortpath
{

std::stack<tuple<long,long,long >> dijkstra(long from, long to, graphs::Graph& G, std::stringstream& steps);

} //namespaceç

namespace minimun_spanning
{
    void prim(long start, graphs::Graph& G, std::stringstream& steps);
    void kruskal(graphs::Graph& G, std::stringstream& steps);
    void findClusters(long size, graphs::Graph& G, std::stringstream& steps);
}

}//algorithms

#endif // AFIRSTSEARCH_H
