#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

class Graph
{
private:
    bool _checkID(int id);
    std::vector<Node*> _nodes;
public:
    Graph() = default;
    const Node* get_node(int id) const;
};

#endif //GRAPH_HPP
