#include <queue>
#include <stack>
#include <vector>
#include "measuretool.h"
#include "graphsalgorithms.h"
#include "heap.h"
#include "disjoint.h"

using namespace algorithms;
using namespace std;
using namespace graphs;
using namespace std::chrono;

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
    measure::MeasureTool tool;
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

    high_resolution_clock::time_point tBegin = high_resolution_clock::now();

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

    tool.measureTime(tBegin,steps);
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
    measure::MeasureTool tool;
    steps << "Tree DFS:" << endl;
    if(T.empty())
    {
        steps << "\tError: It's not possible to build a Tree from an empty Graphic." << endl;
        return;
    }

    T.disableAll();
    steps << "\tStart to build Tree with DFS, from node [" << root << "]" << endl;

    high_resolution_clock::time_point tBegin = high_resolution_clock::now();

    vector<short> explored(T.countNodes(),0);
    vector<int> parents(T.countNodes(),-1);

    DFS(root, explored, parents, T, steps); //recursive function to replace a stack structure, use the call stack

    tool.measureTime(tBegin,steps);

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
bool AFirstSearch::checkDAG(Graph &G, stringstream &steps)
{
    measure::MeasureTool tool;

    steps << "Checking Directed Acyclic Graph (DGA) propertie:" << endl;

    high_resolution_clock::time_point tBegin = high_resolution_clock::now();

    queue<long> topologic;

    bool result = checkDAG(G,topologic,steps);
    if(result)
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
    tool.measureTime(tBegin,steps);

    return result;
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

/**
 * @brief dijkstra
 * @param from The start node.
 * @param to The end node
 * @param G The Graph
 * @param steps Stringstream wich received the log.
 * @return A stack of tuples with: <NodeId, EdgeId, Cost>
 */
stack<tuple<long,long,long >> shortpath::dijkstra(long from, long to, graphs::Graph& G, std::stringstream& steps)
{
    measure::MeasureTool tool;

    steps << "Dijkstra: Searching for the shorted Path from [" << from << "] to [" << to << "]"  << endl;

    collections::Heap<Node*> heap; //To handle the universe of Nodes which are not discovere and to update the cost of each node

    vector<long> fromNode(G.countNodes(),-1); //To handle the cost to reach each node.
    vector<long> fromEdge(G.countNodes(),-1); //To handle the cost to reach each node.
    vector<size_t> costNode(G.countNodes()); //To store the cost of each node.
    stack<tuple<long,long,long >> path; //<idNode, idEdge, Cost>

    high_resolution_clock::time_point tBegin = high_resolution_clock::now();

    //1. Init Structures //T(n log(n))
    vector<long> nodeKeys = G.NodeKeys();
    for(long keyNode : nodeKeys)
    {
        stringstream temp;
        bool isRoot = keyNode == from;
        costNode[keyNode] = isRoot ? 0 : collections::HEAP_INIFITY_KEY;

        Node* n = &G[keyNode];
        if(keyNode != from)
            heap.Insert(collections::HEAP_INIFITY_KEY, n,temp); //Store a copy of the Node with its key.
    }

    //2.Process each node.
    long currentNode = from;
    while(!heap.empty()) //T(n)
    {
        stringstream temp;
        vector<pair<long,long>> adjs = G[currentNode].getAdyacentNodes();

        //2.1. Update Costs
        for(pair<long,long> x : adjs)
        {
            long node = x.first;

            size_t newCost = G(x.second).Length();
            newCost += costNode[currentNode];

            if(costNode[node] > newCost)
            {
                Node* n = &G[node];
                size_t position = heap.Position(n);
                heap.changeKey(position, newCost,temp);
                costNode[node] = newCost;
                fromNode[node] = currentNode;
                fromEdge[node] = x.second;
            }
        }

        bool success;
        Node* n = heap.ExtractFirst(success,temp);
        currentNode = n->ID();
    }

    currentNode = to;

    while(currentNode != -1)
    {
        path.push(tuple<long,long,long>(currentNode, fromEdge[currentNode],costNode[currentNode]));
        currentNode = fromNode[currentNode];
    }

    steps << endl;

    tool.measureTime(tBegin,steps);

    return path;
}

/**
 * @brief minimun_spanning::prim This function implements the PRIM Algorith to find the Minimum Spannig Tree.
 * @param G The Graph which will be optimized.
 * @param steps
 */
void minimun_spanning::prim(long start, graphs::Graph& G, std::stringstream& steps)
{
    //bool result{true};
    measure::MeasureTool tool;

    steps << "PRIM: Minimum Spanning Tree." << endl;

    vector<long> fromEdge(G.countNodes(),-1); //To handle the cost to reach each node.
    vector<size_t> costNode(G.countNodes()); //To store the cost of each node.
    collections::Heap<Node*> heap; //To handle the universe of Nodes which are not discovere and to update the cost of each node

    G.disableAll(); // T(n + m); n=nodes, m= edges

    high_resolution_clock::time_point tBegin = high_resolution_clock::now();

    //T(n log(n) )
    vector<long> nodeKeys = G.NodeKeys();
    for(long keyNode : nodeKeys) //T(n)
    {
        stringstream temp;
        bool isRoot = keyNode == start;
        costNode[keyNode] = isRoot ? 0 : collections::HEAP_INIFITY_KEY;

        Node* n = &G[keyNode];
        if(keyNode != start)
            heap.Insert(collections::HEAP_INIFITY_KEY, n,temp); // T(log(n))
    }

    long currentNode = start;
    while(!heap.empty()) // T(n)
    {
        stringstream temp;
        vector<pair<long,long>> adjs = G[currentNode].getAdyacentNodes();
        G[currentNode].enable(true); //Enable (Discover) the node
        steps << "\t Node: " << currentNode << " has been discovered" << endl;

        //2.1. Update Costs
        for(pair<long,long> x : adjs) // T(m long(n-1))
        {
            long node = x.first;

            size_t newCost = G(x.second).Length();
            newCost += costNode[currentNode];

            if(costNode[node] > newCost)
            {
                Node* n = &G[node];
                size_t position = heap.Position(n);
                heap.changeKey(position, newCost,temp); // T( long(n-1) )

                costNode[node] = newCost;
                //fromNode[node] = currentNode;

                //Update Edges which has the lesser cost to the adj node.
                if(fromEdge[node] != -1)
                {
                    G(fromEdge[node]).enable(false);
                    steps << "\t Edge: " << fromEdge[node] << " has been disabled." << endl;
                }

                fromEdge[node] = x.second;
                G(fromEdge[node]).enable(true);
                steps << "\t Edge: " << fromEdge[node] << " has been enabled." << endl;

            }
        }

        bool success;
        Node* n = heap.ExtractFirst(success,temp); //T(1)
        currentNode = n->ID();
    }

    G[currentNode].enable(true); //Enable (Discover) the node
    steps << "\t Node: " << currentNode << " has been discovered" << endl;

    steps << endl;

    tool.measureTime(tBegin,steps);
}


/**
 * @brief minimun_spanning::kruskal
 * @param start
 * @param G
 * @param steps
 */
void minimun_spanning::kruskal(graphs::Graph& G, std::stringstream& steps)
{
    std::stringstream temp;
    measure::MeasureTool tool;

    steps << "Kruskal: Minimum Spanning Tree." << endl;

    collections::Disjoint_Set<long> djSet;
    collections::Heap<Edge*> heap; //To handle the universe of Nodes which are not discovere and to update the cost of each node

    G.disableAll(); // T(n + m); n=nodes, m= edges

    high_resolution_clock::time_point tBegin = high_resolution_clock::now();

    djSet.MakeUnionFind(G.NodeKeys()); //T(n)

    vector<long> edges = G.EdgeKeys();
    for(long m : edges)
    {
        Edge* edge = &G(m);
        heap.Insert(G(m).Length(),edge,temp );
    }

    while(!heap.empty())
    {
        bool success{true};
        Edge* m = heap.ExtractFirst(success,temp);

        long s = djSet.Union( djSet.Find(m->From()), djSet.Find(m->To()) );
        if(s >= 0)
        {
            steps << "\tNew Set Created/Update[" << s << "]" << endl
                  << "\t\tNodes [" << m->From() << "-" << m->To() << "] linked to the  with edge [" << m->ID() << "]" << endl;
            G[m->From()].enable(true);
            G[m->To()].enable(true);
            G(m->ID()).enable(true);
        }
    }

    tool.measureTime(tBegin,steps);
}

/**
 * @brief minimun_spanning::findClusters
 * @param G
 * @param steps
 */
void minimun_spanning::findClusters(long size, graphs::Graph& G, std::stringstream& steps)
{
    std::stringstream temp;
    measure::MeasureTool tool;

    steps << "Finding [" << size << "] Clusters." << endl;

    collections::Disjoint_Set<long> djSet;
    collections::Heap<Edge*> heap; //To handle the universe of Nodes which are not discovere and to update the cost of each node

    G.disableAll(); // T(n + m); n=nodes, m= edges

    high_resolution_clock::time_point tBegin = high_resolution_clock::now();

    djSet.MakeUnionFind(G.NodeKeys()); //T(n)

    vector<long> edges = G.EdgeKeys();
    for(long m : edges)
    {
        Edge* edge = &G(m);
        heap.Insert(G(m).Length(),edge,temp );
    }

    size--;
    while(!heap.empty())
    {
        bool success{true};
        Edge* m = heap.ExtractFirst(success,temp);

        if(heap.size() >= size)
        {
            long s = djSet.Union( djSet.Find(m->From()), djSet.Find(m->To()) );
            if(s >= 0)
            {
                steps << "\tNew Set Created/Update[" << s << "]" << endl
                      << "\t\tNodes [" << m->From() << "-" << m->To() << "] linked to the  with edge [" << m->ID() << "]" << endl;
                G(m->ID()).enable(true);
            }
            //counter++;
        }

        G[m->From()].enable(true);
        G[m->To()].enable(true);
    }

    tool.measureTime(tBegin,steps);
}
