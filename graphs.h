#ifndef GRAPHS_H
#define GRAPHS_H

#include<map>
#include<vector>

using namespace std;

namespace graphs {

class Node;
class Edge;

class Edge{
    long _id;
    long _length;
    vector<long> _nodes;
    bool _enabled;
public:
    Edge()=default;
    Edge(long id, long length, long from, long to):_id{id},_length{length},_nodes{from,to},_enabled{true}{}

    long ID(){return _id;}
    long Length(){return _length;}
    void updateLenght(long length){_length = length; }
    void enable(bool bEnb){_enabled=bEnb;}
    bool isEnabled(){return _enabled;}
};

class Node{
    long _id;
    //each pair represents the Node and the Edge <idNode,idEdge>
    map<long,long> _eIn;    //The Adyacent inpunt vertex
    map<long,long> _eOut;   //The Adyacent output vertex
    bool _enabled;
public:
    Node()=default;
    Node(long id):_id{id},_eIn{},_eOut{},_enabled{true}{}

    long ID() const {return _id;}
    void enable(bool bEnb){_enabled=bEnb;}
    bool isEnabled() const {return _enabled;}

    void addAdyacenteNodes(long idAdjV, long idEdge, bool isIncomming=false)
    {
        bool execute;
        //Valid if the Node has not been connected yet.
        execute = isIncomming? _eIn.find(idAdjV) == _eIn.end() : _eOut.find(idAdjV) == _eOut.end();

        if(!execute) return;

        if(isIncomming)
            _eIn.insert(std::pair<long,long>(idAdjV,idEdge));
        else
            _eOut.insert(std::pair<long,long>(idAdjV,idEdge));
    }

    vector<pair<long,long>> getAdyacentNodes(bool fromIncomming = false)
    {
        size_t size = fromIncomming? _eIn.size() : _eOut.size();

        map<long,long>::iterator it = fromIncomming ? _eIn.begin() : _eOut.begin();
        map<long,long>::iterator end = fromIncomming ? _eIn.end() : _eOut.end();
        vector<std::pair<long,long>> vtrxs(size);
        size_t i = 0;

        while(it != end)
        {
            vtrxs[i] = std::make_pair(it->first,it->second);
            i++;
            it++;
        }

        return vtrxs;
    }

    long countNodesAdy(bool isIncomming=false)
    {
        return isIncomming? _eIn.size() : _eOut.size();
    }

    void removeAdyacentNode(long id)
    {
        _eIn.erase(id);
        _eOut.erase(id);
    }
};

class Graph{
    map<long, Node> _nodes;
    map<long, Edge> _edges;

    long createEdge(long length, long from, long to)
    {
        long id = _edges.size();
        Edge e(id,length, from, to);
        _edges.insert(std::pair<long,Edge>(id,e));
        return id;
    }

public:
    Graph():_nodes{},_edges{}{}

    ~Graph()
    {
        clear();
    }

    bool empty() const
    {
        return _nodes.empty();
    }

    void clear()
    {
        _nodes.clear();
        _edges.clear();
    }

    void disableAll()
    {
        map<long, Node>::iterator itv;
        map<long, Edge>::iterator ite;

        for(itv = _nodes.begin(); itv != _nodes.end(); itv++)
            itv->second.enable(false);

        for(ite = _edges.begin(); ite != _edges.end(); ite++)
            ite->second.enable(false);
    }

    long countNodes() const{
        return _nodes.size();
    }

    long countEdges() const{
        return _edges.size();
    }

    long createNode(){
        long id = _nodes.size();// + 1;
        Node v(id);
        _nodes[id] = v;
        return id;
    }

    Node& operator[](long id)
    {
        if(_nodes.find(id) == _nodes.end())
            throw runtime_error("There is no such Node.");
        return _nodes[id];
    }

    Edge& operator()(long id)
    {
        if(_edges.find(id) == _edges.end())
            throw runtime_error("There is no such Edge.");
        return _edges[id];
    }

    vector<long> NodeKeys()
    {
        vector<long> keys(_nodes.size(),-1);
        map<long, Node>::iterator it = _nodes.begin();

        size_t i = 0;
        while(it != _nodes.end())
        {
            keys[i++] =it->first;
            it++;
        }

        return keys;
    }

    vector<long> EdgeKeys()
    {
        vector<long> keys(_edges.size(),-1);
        map<long, Edge>::iterator it = _edges.begin();

        size_t i = 0;
        while(it != _edges.end())
        {
            keys[i++] =it->first;
            it++;
        }

        return keys;
    }

    long connectNodes(long vOut, long vIn, long length, bool directed = false)
    {
        long id{0};

        Node& from = _nodes[vOut];
        Node& to = _nodes[vIn];


        id = createEdge(length,vOut, vIn);
        from.addAdyacenteNodes(to.ID(),id);
        to.addAdyacenteNodes(from.ID(),id, directed ? true:false);

        return id;
    }

    void removeNode(long id)
    {
        map<long, Node>::iterator it = _nodes.find(id);

        if(it != _nodes.end())
        {
            vector<pair<long,long>> vxs = _nodes[id].getAdyacentNodes();
            for(pair<long,long> va : vxs)
            {
                long idV = va.first;
                long idE = va.second;
                _nodes[idV].removeAdyacentNode(id); //unlink the Vertext from its adjancentes Vertexes.
                _edges.erase(idE); //Remove the Edge linked to the adjancentes Vertex.
            }

            _nodes.erase(id); //remove the Vertex from the graph.
        }
    }

    void updateEdgeLength(long id, long length)
    {
        map<long, Edge>::iterator it;
        it = _edges.find(id);
        if(it != _edges.end())
            it->second.updateLenght(length);
    }
};

}//namespace


#endif // GRAPHS_H
