#include "tnode.h"


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
    return _adjs.size();
}

void TNode::addAdjacentNode(int node, int edge)
{
    std::pair<int,int> tnode(node, edge);
    _adjs.push_back(tnode);
}

std::pair<int,int> TNode::getAdjacent(int index)
{

    if(index >= _adjs.size() || index < 0) return std::make_pair(-1, -1);

    return _adjs[index];
}
