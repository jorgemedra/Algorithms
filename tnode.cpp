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

void TNode::setActive(bool value)
{
    _bActive = value;
}

bool TNode::isActive()
{
    return _bActive;
}

int TNode::sizeOfAdjacent()
{
    return _adjsOut.size();
}

void TNode::addAdjacentNode(int node, int edge, bool isOut)
{
    std::pair<int,int> tnode(node, edge);
    if(isOut)
        _adjsOut.push_back(tnode);
    else
        _adjsIn.push_back(tnode);
}

std::pair<int,int> TNode::getAdjacent(int index)
{

    if(index >= _adjsOut.size() || index < 0) return std::make_pair(-1, -1);

    return _adjsOut[index];
}
