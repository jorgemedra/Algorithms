#ifndef GRAPHS_H
#define GRAPHS_H

#include <vector>

namespace algorithms
{
    namespace graphs {

        class Node;
        class Edge;

        class Graph{
            bool _directed;
            std::vector<Node> _nodes;
            std::vector<Edge> _edges;

        public:
            Graph(bool directed=false);
            void addNode(int id);
            void linkNodes(int idNodeB,int idNodeE, int idEdge, long length);

            bool empty();
            int countNodes();
            int countEdges();
            Node& operator[](int index);
            Edge& operator()(int index);

            std::vector<Node> Nodes();
            void clear();
        };

        class Node{
            int _id;
            std::vector<std::pair<int,int>> _nodesAdjIn;
            std::vector<std::pair<int,int>> _nodesAdjOut;

        public:
            Node():_id{-1}, _nodesAdjIn{}, _nodesAdjOut{}{}
            Node(int id);

            int ID();

            int countNodesAdj(bool adjIn=false);
            void linkNode(int idNode, int idEdge, bool isIn=false);
            std::pair<int,int> nodeAdj(int index, bool isIn=false);
        };

        class Edge{
            int _id{-1};
            long _length{-1L};
            int _NodeBegin{-1};
            int _NodeEnd{-1};

        public:
            Edge():_id{-1}, _length{-1L}, _NodeBegin{-1},  _NodeEnd{-1}{}
            Edge(int id, int nIni, int nEnd, long len);

            int ID();
            int Begine();
            int End();
            long length();
            void setLength(long len);
        };

    }//graphs

}//algorithms

#endif // GRAPHS_H
