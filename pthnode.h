#ifndef PTHNODE_H
#define PTHNODE_H

#include <utility>
#include <vector>
#include <tuple>

class PathNode
{
    int _id;
    int _parent;
    std::vector<std::tuple<int,int,long>> _adjsOut;
    std::vector<std::tuple<int,int,long>> _adjsIn;
    std::vector<long> _edgeLng;

public:
    PathNode(int id):_id{id},_parent{-1},_adjsOut{},_adjsIn{},_edgeLng{}{}

    int getId();
    void setParent(int _idP);
    int getParent();
    int sizeOfAdjacent();
    void addAdjacentNode(int node, int edge, long elength, bool isOut=true);

    int getSizeOfAdjacentNodes(bool incomming);
    std::tuple<int,int,long> getAdjacentOut(int index);
    std::tuple<int,int,long> getAdjacentIn(int index);
};

#endif // PTHNODE_H
