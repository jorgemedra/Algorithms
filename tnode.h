#ifndef TNODE_H
#define TNODE_H

#include <utility>
#include <vector>
class TNode
{
    int _id;
    int _parent;
    bool _bActive;
    std::vector<std::pair<int,int>> _adjsOut;
    std::vector<std::pair<int,int>> _adjsIn;

public:
    TNode(int id):_id(id),_parent(-1),_bActive(true){}

    int getId();
    void setParent(int _idP);
    int getParent();
    void setActive(bool value);
    bool isActive();
    int sizeOfAdjacent();
    void addAdjacentNode(int node, int edge, bool isOut=true);
    std::pair<int,int> getAdjacent(int index);



};

#endif // TNODE_H
