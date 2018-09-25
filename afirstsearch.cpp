#include <queue>
#include <stack>
#include <vector>
#include "afirstsearch.h"

using namespace algorithms;
using namespace std;
using namespace algorithms::graphs;

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
void AFirstSearch::BFS(int root, Graph &G, Graph &T, stringstream &steps,bool checkBipartitenes)
{
    //queue<TNode*> levelQueue;
    queue<Node> levelQueue;
    T.clear();

    steps << "Tree BFS:" << endl;
    if(G.empty())
    {
        steps << "\tError: It's not possible to build a Tree from an empty Graphic." << endl;
        return;
    }

    vector<bool> discovey(G.countNodes(),false);
    vector<int> parents(G.countNodes(), -1);
    vector<int> layerByNode(G.countNodes(), -1);
    vector<bool> isOdd(G.countNodes(), false);

    T.clear();

    T.addNode(root);
    levelQueue.push(G[root]);
    discovey[root] = true;
    parents[root] = -1;
    layerByNode[root] = 0; //The root node is layer 0.
    isOdd[root] = true; //The firt node is Odd

    steps << "\tStart to build Tree with BFS, from node [" << root << "]" << endl;

    while(!levelQueue.empty())
    {
        Node node = levelQueue.front();
        int adjNodes = node.countNodesAdj();
        levelQueue.pop();

        //Check childs
        for(int i=0; i < adjNodes; i++)
        {
            std::pair<int,int> adj = node.nodeAdj(i);
            int idNode_ = adj.first;
            int idEdge_ = adj.second;

            if(!discovey[idNode_])
            {
                steps << "\t\tNew Node [" << idNode_ << "] discovery from Node [" << node.ID() << "] with Edge (" <<  idEdge_ << ")" << endl;

                T.addNode(idNode_);
                T.linkNodes(node.ID(), idNode_, idEdge_, G(idEdge_).length());
                parents[idNode_] = node.ID();
                levelQueue.push(G[idNode_]); //Add the node into the queue (Adding to one level upper)..
                discovey[idNode_] = true;

                layerByNode[idNode_] = layerByNode[node.ID()] + 1; //The new child discovered has a upper level.
                isOdd[idNode_] = !isOdd[node.ID()]; //The child must be the opposit of its parent (Odd or Even).
            }
            else
            {
                if(!checkBipartitenes && isOdd[idNode_] == isOdd[node.ID()])
                    steps << "\t\t**The edge with nodes [" << idNode_ << "] and [" << node.ID() << "] are not allowing the Graph to comply with the Bipartiteness propertie.**" << endl;
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
void AFirstSearch::DFS(int root, Graph &G, Graph &T, stringstream &steps)
{
    steps << "Tree DFS:" << endl;
    if(G.empty())
    {
        steps << "\tError: It's not possible to build a Tree from an empty Graphic." << endl;
        return;
    }

    T.clear();
    steps << "\tStart to build Tree with DFS, from node [" << root << "]" << endl;

    vector<short> explored(G.countNodes(),0);
    vector<int> parents(G.countNodes(),-1);

    DFS(root, explored, parents, G, T, steps); //recursive function to replace a stack structure, use the call stack
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
void AFirstSearch::DFS(int root, vector<short>& explored, vector<int>& parents,
                       Graph &G, Graph &T, stringstream &steps )
{
    T.addNode(G[root].ID());
    explored[G[root].ID()] = 1; //explored

    steps << "\t\tNew Node [" << G[root].ID() << "] explored from Parent Node [" << parents[G[root].ID()] << "]" << endl;

    for(int i=0; i< G[root].countNodesAdj(); i++)
    {
        std::pair<int,int> adj = G[root].nodeAdj(i,false);

        int idNode_ = adj.first;
        int idEdge_ = adj.second;

        if(!explored[idNode_])
        {
            parents[idNode_] = root;
            DFS(idNode_, explored, parents, G, T, steps);
            T.linkNodes(G[root].ID(), idNode_, idEdge_, G(idEdge_).length());
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

    vector<Node> Gc = G.Nodes();
    vector<int> incommingCount(G.countNodes(),0);
    queue<int> topologic;

    for(int i=0; i < (int)G.countNodes(); i++)
        incommingCount[i] = Gc[i].countNodesAdj(true);
        //incommingCount[i] = Gc[i].nodeAdj(i,true).first;

    //Check the DAG property
    bool bContinue;
    do
    {
        bContinue = false;

        //if(G.countNodes() > 1)
        if(Gc.size() > 1)
        {
            stack<int> nodesToRemove;
            //queue<int> nodesToUpdate;

            //Look for a node without incomming nodes.
            for(size_t i=0; i< Gc.size(); i++)
            {
                if(incommingCount[Gc[i].ID()] <= 0)
                {
                    topologic.push(Gc[i].ID());   //Add the node Id to the topologic.
                    steps << "\tNode found without incomming node [" << Gc[i].ID() << "] "
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
                for(int j=0; j< Gc[index].countNodesAdj(); j++)
                {
                    int idAdj = Gc[index].nodeAdj(j).first;
                    incommingCount[idAdj]--;
                }
                Gc.erase(Gc.begin() + index);
            }

            if(!bContinue)
            {
                steps << "\tThis graph desn´t meet the DAG property because has been found a cicle betwen nodes:" << endl
                      << "\t\t[ ";
                for(size_t i=0; i<Gc.size(); i++)
                    steps << Gc[i].ID() << " ";
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
            topologic.push(Gc[0].ID());

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
