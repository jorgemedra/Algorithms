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

int TNode::getSizeOfAdjacentNodes(bool incomming)
{
    if(incomming)
        return _adjsIn.size();

    return _adjsOut.size();
}

std::pair<int,int> TNode::getAdjacentOut(int index)
{

    if(index >= _adjsOut.size() || index < 0) return std::make_pair(-1, -1);

    return _adjsOut[index];
}


std::pair<int,int> TNode::getAdjacentIn(int index)
{
    if(index >= _adjsIn.size() || index < 0) return std::make_pair(-1, -1);

    return _adjsIn[index];
}
