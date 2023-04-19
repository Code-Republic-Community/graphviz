#ifndef EXAMPLES_GOLDEN_GRAPH_GRAPH_HPP
#define EXAMPLES_GOLDEN_GRAPH_GRAPH_HPP

#include "node.hpp"
#include <vector>

class Graph
{
public:
    Graph() = default;
public:
    const Node* getNode(int id) const;
    const std::vector<Node*>& getAllNodes() const;
    void addEdge(int id1, int id2);
private:
    bool m_checkID(int id);
private:
    std::vector<Node*> m_nodes;
};

#endif //EXAMPLES_GOLDEN_GRAPH_GRAPH_HPP
