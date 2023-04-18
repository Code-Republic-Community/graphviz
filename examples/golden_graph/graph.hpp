#ifndef EXAMPLES_GOLDEN_GRAPH_GRAPH_HPP
#define EXAMPLES_GOLDEN_GRAPH_GRAPH_HPP

#include "Node.hpp"
#include <vector>

class Graph
{
public:
    Graph() = default;
public:
    const Node* getNode(int) const;
    const std::vector<Node*>& getAllNodes() const;
private:
    bool _checkID(int id);
private:
    std::vector<Node*> m_nodes;
};

#endif //EXAMPLES_GOLDEN_GRAPH_GRAPH_HPP
