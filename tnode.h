#ifndef TNODE_H
#define TNODE_H

#include <utility>
#include <vector>
class TNode
{
    int _id;
    int _parent;
    std::vector<std::pair<int,int>> _adjs;
public:
    TNode(int id):_id(id),_parent(-1){}

    int getId();
    void setParent(int _idP);
    int getParent();
    int sizeOfAdjacent();
    void addAdjacentNode(int node, int edge);
    std::pair<int,int> getAdjacent(int index);



};

#endif // TNODE_H
