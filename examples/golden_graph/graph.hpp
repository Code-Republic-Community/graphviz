#ifndef EXAMPLES_GOLDEN_GRAPH_GRAPH_HPP
#define EXAMPLES_GOLDEN_GRAPH_GRAPH_HPP

#include "node.hpp"

#include <iostream>
#include <vector>

class Graph
{
public:
    Graph() = default;
public:
    const Node* getNode(int id) const;
    const std::vector<Node*>& getAllNodes() const;
    void deleteEdge(int id1, int id2);
    void addEdge(int sourceID, int destinationID);
    void addNode(int id, int value);
private:
    bool m_checkID(int id);
    Node* m_getNode(int id) const;
private:
    std::vector<Node*> m_nodes;
};

#endif //EXAMPLES_GOLDEN_GRAPH_GRAPH_HPP
