#ifndef TNODE_H
#define TNODE_H

#include <utility>
#include <vector>
#include <tuple>

class TNode
{
    int _id;
    int _parent;
    //<std::tuple<int =Node Ide,int = EdgeId,int = Edge Lenght>>
    std::vector<std::tuple<int,int,int>> _adjsOut;
    std::vector<std::tuple<int,int,int>> _adjsIn;

public:
    TNode(int id):_id(id),_parent(-1){}

    int getId();
    void setParent(int _idP);
    int getParent();
    int sizeOfAdjacent();
    void addAdjacentNode(int node, int edge, long lenght, bool isOut=true);

    int getSizeOfAdjacentNodes(bool incomming);
    std::tuple<int,int, long> getAdjacentOut(int index);
    std::tuple<int,int, long> getAdjacentIn(int index);
};

#endif // TNODE_H
