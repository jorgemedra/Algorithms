#include <queue>
#include <stack>
#include <vector>
#include "afirstsearch.h"

using namespace algorithms;
using namespace std;
using namespace graphs;

AFirstSearch::AFirstSearch()
{

}

/**
 * @brief AFirstSearch::BFS This function has the algorith to buil a tree T, from a graph G, using the BFS algorithm.
 * Also, it check if the Graph acomplishes with the Bipartiteness property.
 * @param root root Node which the algorithm start to build the resulting tree.
 * @param G The Original graph.
 * @param T The resulting tree.
 * @param steps The log output.
 * @param checkBipartitenes A flag which indicates if it performes the Bipartitenes validation (True) or not (false).
 */
void AFirstSearch::BFS(long root, Graph &T, stringstream &steps, bool checkBipartitenes)
{
    queue<long> levelQueue;
    vector<bool> discovey(T.countNodes(),false);
    vector<int> parents(T.countNodes(), -1);
    vector<int> layerByNode(T.countNodes(), -1);
    vector<bool> isOdd(T.countNodes(), false);

    steps << "Tree BFS:" << endl;
    if(T.empty())
    {
        steps << "\tError: It's not possible to build a Tree from an empty Graphic." << endl;
        return;
    }

    T.disableAll();

    T[root].enable(true);
    levelQueue.push(root);
    discovey[root] = true;
    parents[root] = -1;
    layerByNode[root] = 0; //The root node is layer 0.
    isOdd[root] = true; //The firt node is Odd

    steps << "\tStart to build Tree with BFS, from node [" << root << "]" << endl;

    while(!levelQueue.empty()) //T(n)
    {
        long node = levelQueue.front();
        vector<std::pair<long,long>> adjNodes = T[node].getAdyacentNodes();
        levelQueue.pop();

        //Check childs
        for(std::pair<long,long> p : adjNodes )
        {
            long idNode_ = p.first;
            long idEdge_ = p.second;

            // T(n-1), where n -1 represents all the possible nodes adyacentes.
            //But it is important to considered that each node wll be procecesd only if it has not been disovered
            if(!discovey[idNode_])
            {
                steps << "\t\tNew Node [" << idNode_ << "] discovery from Node [" << node << "] with Edge (" <<  idEdge_ << ")" << endl;

                T[idNode_].enable(true);
                T(idEdge_).enable(true);
                parents[idNode_] = node;
                levelQueue.push(idNode_); //Add the node into the queue (Adding to one level upper)..
                discovey[idNode_] = true;

                layerByNode[idNode_] = layerByNode[node] + 1; //The new child discovered has a upper level.
                isOdd[idNode_] = !isOdd[node]; //The child must be the opposit of its parent (Odd or Even).
            }
            else
            {
                if(!checkBipartitenes && isOdd[idNode_] == isOdd[node])
                    steps << "\t\t**The edge with nodes [" << idNode_ << "] and [" << node << "] are not allowing the Graph to comply with the Bipartiteness propertie.**" << endl;
            }
        }
    }
}

/**
 * @brief AFirstSearch::DFS Is the main function which prepare al the parameters to invoke the recursive function DFS
 * @param root Node which the algorithm start to build the resulting tree.
 * @param G The Original graph.
 * @param T The resulting tree.
 * @param steps The log output.
 */
void AFirstSearch::DFS(long root, Graph &T, stringstream &steps)
{

    steps << "Tree DFS:" << endl;
    if(T.empty())
    {
        steps << "\tError: It's not possible to build a Tree from an empty Graphic." << endl;
        return;
    }

    T.disableAll();
    steps << "\tStart to build Tree with DFS, from node [" << root << "]" << endl;

    vector<short> explored(T.countNodes(),0);
    vector<int> parents(T.countNodes(),-1);

    DFS(root, explored, parents, T, steps); //recursive function to replace a stack structure, use the call stack

}

/**
 * @brief AFirstSearch::DFS this is the recursive function wich implement a Stak (Call Sctack) that is used to implement the
 * DFS algorithm instead a Stack structure.
 * @param root Node which the algorithm continue building the resulting tree.
 * @param explored Array of nodes which has been explored and haven't.
 * @param parents Array of nodes which are parents into the tree.
 * @param G The Original graph.
 * @param T The resulting tree.
 * @param steps The log output.
 */
void AFirstSearch::DFS(long root, vector<short>& explored, vector<int>& parents,
                       Graph &T, stringstream &steps )
{

    T[root].enable(true);
    explored[root] = 1; //explored

    steps << "\t\tNew Node [" << root << "] explored from Parent Node [" << parents[root] << "]" << endl;

    Node rv = T[root];
    vector<pair<long,long>>adj = rv.getAdyacentNodes();
    for(pair<long,long> vAd : adj)
    {
        int idNode_ = vAd.first;
        int idEdge_ = vAd.second;

        if(!explored[idNode_])
        {
            parents[idNode_] = root;
            DFS(idNode_, explored, parents, T, steps);
            T(idEdge_).enable(true);
        }
    }
}

/**
 * @brief AFirstSearch::checkDAG
 *
 * + The activeNode vector has Ids of each node which is active into the DGA's algorithm tree.
 * + The array incommingCount has the total node that are incomming to the node, each time that a node is removed it drecrease
 * the incommins count from its adjancents nodes.
 *
 * @param G
 * @param steps
 */
void AFirstSearch::checkDAG(Graph &G, stringstream &steps)
{
    steps << "Checking Directed Acyclic Graph (DGA) propertie:" << endl;

    queue<long> topologic;

    if(checkDAG(G,topologic,steps))
    {
        steps << "\tThis graph meets the DAG property and its topologyc founded is:" << endl
              << "\t\t[ ";
        while(!topologic.empty())
        {
            steps << topologic.front() << " ";
            topologic.pop();
        }
        steps << "]" << endl;
    }
    else
    {
        vector<long> vrtxs = G.NodeKeys();

        steps << "\tThis graph doesn´t meet the DAG property because has been found a cicle betwen nodes:" << endl
              << "\t\t[ ";

        for(long k : vrtxs)
            steps << k << " ";
        steps << "]" << endl;

        steps << "\tThis was the topologic that could be detected before found the cycle:" << endl
              << "\t\t[ ";
        while(!topologic.empty())
        {
            steps << topologic.front() << " ";
            topologic.pop();
        }
        steps << "]" << endl;
    }
}

bool AFirstSearch::checkDAG(graphs::Graph &G, queue<long>& topologic , std::stringstream &steps)
{
    vector<long> vrtxs = G.NodeKeys();

    //1.- find a Vertex without incoming nodes.
    for(size_t i=0; i < vrtxs.size(); i++)
    {
        if(G[vrtxs[i]].countNodesAdy(true) == 0)
        {
            topologic.push(vrtxs[i]);
            G.removeNode(vrtxs[i]);

            if(G.countNodes() > 0)
                return checkDAG(G,topologic,steps);
            else
                return true;
        }
    }

    return false;
}
