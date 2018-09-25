#include "tnode.h"

using namespace std;

int  TNode::getId()
{
    return _id;
}

void TNode::setParent(int _idP)
{
    _parent = _idP;
}

int TNode::getParent()
{
    return _parent;
}

int TNode::sizeOfAdjacent()
{
    return _adjsOut.size();
}

void TNode::addAdjacentNode(int node, int edge, long lenght, bool isOut)
{
    tuple<int,int,int> tnode(node, edge, lenght);
    if(isOut)
        _adjsOut.push_back(tnode);
    else
        _adjsIn.push_back(tnode);
}

int TNode::getSizeOfAdjacentNodes(bool incomming)
{
    if(incomming)
        return _adjsIn.size();

    return _adjsOut.size();
}

std::tuple<int,int,long> TNode::getAdjacentOut(int index)
{

    if(index >= _adjsOut.size() || index < 0) return std::make_tuple(-1, -1, 1L);

    return _adjsOut[index];
}


std::tuple<int,int, long> TNode::getAdjacentIn(int index)
{
    if(index >= _adjsIn.size() || index < 0) return std::make_tuple(-1, -1, 1L);

    return _adjsIn[index];
}
