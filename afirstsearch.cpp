#include "afirstsearch.h"
#include <queue>
#include <stack>
#include <vector>

using namespace algorithms;
using namespace std;

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
void AFirstSearch::BFS(int root, vector<TNode*> &G, vector<TNode*> &T, stringstream &steps,bool checkBipartitenes)
{
    queue<TNode*> levelQueue;

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
            std::pair<int,int> adj = node->getAdjacentOut(i);

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
                if(!checkBipartitenes && isOdd[adj.first] == isOdd[node->getId()])
                    steps << "\t\t**The edge with nodes [" << adj.first << "] and [" << node->getId() << "] are not allowing the Graph to comply with the Bipartiteness propertie.**" << endl;
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
        std::pair<int,int> adj = node->getAdjacentOut(i);
        if(!explored[adj.first])
        {
            parents[adj.first] = root;
            tn->addAdjacentNode(adj.first, adj.second);
            DFS(adj.first, explored, parents, G, T, steps);
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
void AFirstSearch::checkDAG(vector<TNode*> &G, stringstream &steps)
{
    steps << "Checking Directed Acyclic Graph (DGA) propertie:" << endl;

    vector<TNode*> Gc(G); //Clone the original Graph
    vector<int> incommingCount(Gc.size(),0);
    queue<int> topologic;

    for(int i=0; i < (int)Gc.size(); i++)
        incommingCount[i] = Gc[i]->getSizeOfAdjacentNodes(true);

    //Check the DAG property
    bool bContinue;
    do
    {
        bContinue = false;

        if(Gc.size() > 1)
        {
            stack<int> nodesToRemove;
            //queue<int> nodesToUpdate;

            //Look for a node without incomming nodes.
            for(int i=0; i< (int)Gc.size(); i++)
            {
                if(incommingCount[Gc[i]->getId()] <= 0)
                {
                    topologic.push(Gc[i]->getId());   //Add the node Id to the topologic.
                    steps << "\tNode found without incomming node [" << Gc[i]->getId() << "] "
                          << "was added at topolic." << endl;

                    bContinue = true;
                    nodesToRemove.push(i);
                }
            }

            //Remove Node from the graph
            while(!nodesToRemove.empty())
            {
                int index = nodesToRemove.top();
                nodesToRemove.pop();

                //Update the incomming node adjacentes.
                for(int j=0; j< Gc[index]->getSizeOfAdjacentNodes(false); j++)
                {
                    int idAdj = Gc[index]->getAdjacentOut(j).first;
                    incommingCount[idAdj]--;
                }
                Gc.erase(Gc.begin() + index);
            }

            if(!bContinue)
            {
                steps << "\tThis graph desn´t meet the DAG property because has been found a cicle betwen nodes:" << endl
                      << "\t\t[ ";
                for(int i=0; i<Gc.size(); i++)
                    steps << Gc[i]->getId() << " ";
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
        else if(topologic.size() > 0)
        {
            topologic.push(Gc[0]->getId());

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
            steps << "\tThere is just one node in the Graph, is not necessary analyze the propertie DAG." << endl;


    }while(bContinue);

}
