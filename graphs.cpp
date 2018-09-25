#include "graphs.h"


using namespace algorithms::graphs;
using namespace std;


/**********************
*        GRAPH        *
**********************/

Graph::Graph(bool directed):
    _directed{directed},
    _nodes{},
    _edges{}
{}

void Graph::addNode(int id)
{
    if((id+1) > _nodes.size()) _nodes.resize((id+1));
    _nodes[id] = Node{id};
}

void Graph::linkNodes(int idNodeB,int idNodeE, int idEdge, long length)
{
    if((idEdge+1) > _edges.size()) _edges.resize((idEdge+1));

    _edges[idEdge] = Edge{idEdge, idNodeB, idNodeE, length};

    _nodes[idNodeB].linkNode(idNodeE, idEdge); //Link the Output Node (idNodeE).
    _nodes[idNodeE].linkNode(idNodeB, idEdge, _directed);//directed means all the nodes are Output
}

Node& Graph::operator[](int index)
{
    if(index < 0 || index >= _nodes.size()) throw std::out_of_range("Index Out of Bound.");
    return _nodes[index];
}

Edge& Graph::operator()(int index)
{
    if(index < 0 || index >= _edges.size()) throw std::out_of_range("Index Out of Bound.");
    return _edges[index];
}

int Graph::countNodes()
{
    return _nodes.size();
}

int Graph::countEdges()
{
    return _edges.size();
}

bool Graph::empty()
{
    return _nodes.size() > 0 ? false : true;
}

void Graph::clear()
{
    _nodes.clear();
    _nodes.resize(0);
    _edges.clear();
    _nodes.resize(0);
}

std::vector<Node> Graph::Nodes()
{
    return _nodes;
}

/**********************
*        NODE         *
**********************/

Node::Node(int id):_id{id}{}

int Node::ID(){return _id;}

int Node::countNodesAdj(bool adjIn)
{
    return adjIn ? _nodesAdjIn.size() : _nodesAdjOut.size();
}

void Node::linkNode(int idNode, int idEdge, bool isIn)
{
    if(isIn) _nodesAdjIn.push_back(std::make_pair(idNode,idEdge));
    else _nodesAdjOut.push_back(std::make_pair(idNode,idEdge));
}

pair<int,int> Node::nodeAdj(int index, bool isIn)
{
    if(index < 0 || index >= (isIn ? _nodesAdjIn.size() : _nodesAdjOut.size())) throw std::out_of_range("Index Out of Bound.");
    return isIn ? _nodesAdjIn[index] : _nodesAdjOut[index];
}


/**********************
*        EDGE         *
**********************/

Edge::Edge(int id, int nIni, int nEnd, long len):
    _id{id},
    _NodeBegin{nIni},
    _NodeEnd{nEnd},
    _length{len}
{}

int Edge::ID(){return _id;}

int Edge::Begine(){return _NodeBegin;}

int Edge::End(){return _NodeEnd;}

long Edge::length(){return _length;}

void Edge::setLength(long len){_length = len;}
