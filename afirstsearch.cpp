#include "afirstsearch.h"
#include <queue>
#include <stack>
#include <vector>

using namespace algorithms;
using namespace std;

AFirstSearch::AFirstSearch()
{

}

void AFirstSearch::BFS(int root, vector<TNode*> &G, vector<TNode*> &T, stringstream &steps)
{
    queue<TNode*> levelQueue;
    bool currentOddStatus = true;

    steps << "Tree BFS:" << endl;
    if(G.empty())
    {
        steps << "\tError: It's not possible to build a Tree from an empty Graphic." << endl;
        return;
    }

    vector<bool> discovey(G.size(),false);
    vector<int> parents(G.size(), -1);
    vector<int> layerByNode(G.size(), -1);
    vector<bool> isOdd(G.size(), false);

    T.clear();
    T.resize(G.size());

    levelQueue.push(G[root]);
    discovey[root] = true;
    parents[root] = -1;
    layerByNode[root] = 0; //The root node is layer 0.
    isOdd[root] = true; //The firt node is Odd

    steps << "\tStart to build Tree with BFS, from node [" << root << "]" << endl;

    while(!levelQueue.empty())
    {
        TNode* node = levelQueue.front();
        int adjNodes = node->sizeOfAdjacent();
        levelQueue.pop();

        TNode* tn = new TNode(node->getId());
        tn->setParent(parents[node->getId()]);
        T[node->getId()] = tn; //set the node at the Tree

        //Check childs
        for(int i=0; i < adjNodes; i++)
        {
            std::pair<int,int> adj = node->getAdjacent(i);

            if(!discovey[adj.first])
            {
                steps << "\t\tNew Node [" << adj.first << "] discovery from Node [" << node->getId() << "]" << endl;

                tn->addAdjacentNode(adj.first,adj.second); //add the node and the edge which leading to it
                parents[adj.first] = tn->getId();
                levelQueue.push(G[adj.first]); //Add the nodo at the queue (Adding to one level upper)..
                discovey[adj.first] = true;

                layerByNode[adj.first] = layerByNode[node->getId()] + 1; //The new child discovered has a upper level.
                isOdd[adj.first] = !isOdd[node->getId()]; //The child must be the opposit of its parent (Odd or Even).
            }
            else
            {
                if(isOdd[adj.first] == isOdd[node->getId()])
                    steps << "\t\t**The edge with nodes [" << adj.first << "] and [" << node->getId() << "] are not allowing the Graph to comply with the Bipartiteness propertie.**" << endl;
            }
        }
    }

}


void AFirstSearch::DFS(int root, vector<TNode*> &G, vector<TNode*> &T, stringstream &steps)
{
    steps << "Tree DFS:" << endl;
    if(G.empty())
    {
        steps << "\tError: It's not possible to build a Tree from an empty Graphic." << endl;
        return;
    }

    steps << "\tStart to build Tree with DFS, from node [" << root << "]" << endl;

    bool* explored = new bool[G.size()];
    int* parents = new int[G.size()];

    T.clear();
    T.resize(G.size());

    for(int i=0; i < (int)G.size(); i++)
    {
        explored[i]=false;
        parents[i]=-1;
    }

    DFS(root, explored, parents, G, T, steps); //recursive function to replace a stack structure, use the call stack

    delete[] explored;
    delete[] parents;
}


void AFirstSearch::DFS(int root, bool* explored, int* parents, vector<TNode*> &G, vector<TNode*> &T, stringstream &steps )
{
    TNode* node = G[root];
    TNode* tn = new TNode(node->getId());
    tn->setParent(parents[node->getId()]);
    T[node->getId()] = tn; //set the node at the Tree

    explored[node->getId()] = true;
    int adjNodes = node->sizeOfAdjacent();

    steps << "\t\tNew Node [" << node->getId() << "] explored from Parent Node [" << parents[node->getId()] << "]" << endl;

    for(int i=0; i< adjNodes; i++)
    {
        std::pair<int,int> adj = node->getAdjacent(i);
        if(!explored[adj.first])
        {
            parents[adj.first] = root;
            tn->addAdjacentNode(adj.first, adj.second);
            DFS(adj.first, explored, parents, G, T, steps);
        }
    }
}
