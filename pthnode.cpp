/****************************************

  std::tuple<int,int,long>

  <0>: Node Id.
  <1>: Edge Id.
  <2>: Edgen Length.

 ****************************************/

#include "pthnode.h"

int  PathNode::getId()
{
    return _id;
}

void PathNode::setParent(int _idP)
{
    _parent = _idP;
}

int PathNode::getParent()
{
    return _parent;
}

int PathNode::sizeOfAdjacent()
{
    return _adjsOut.size();
}

void PathNode::addAdjacentNode(int node, int edge, long elength, bool isOut)
{
    std::tuple<int,int, long> pnode(node, edge, elength);

    if(isOut) _adjsOut.push_back(pnode);
    else _adjsIn.push_back(pnode);
}

int PathNode::getSizeOfAdjacentNodes(bool incomming)
{
    if(incomming)
        return _adjsIn.size();

    return _adjsOut.size();
}

std::tuple<int,int,long> PathNode::getAdjacentOut(int index)
{

    if(index >= (int)_adjsOut.size() || index < 0) return std::make_tuple(-1, -1, 0);

    return _adjsOut[index];
}


std::tuple<int,int,long> PathNode::getAdjacentIn(int index)
{
    if(index >= (int)_adjsIn.size() || index < 0) return std::make_tuple(-1, -1, 0);

    return _adjsIn[index];
}
