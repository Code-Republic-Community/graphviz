#ifndef EXAMPLES_GOLDEN_GRAPH_NODE_HPP
#define EXAMPLES_GOLDEN_GRAPH_NODE_HPP

#include <iostream>
#include <vector>

#include "edge.hpp"

class Node {
   public:
    Node(int id, int value);

   public:
    void deleteThis();
    void setValue(int value);
    int getID() const;
    int getValue() const;
    void addEdge(int id, Direction direction);
    const std::vector<Edge*>& getEdges() const;
    void print() const;
    void deleteEdge(int edgeID);

   private:
    int m_ID;
    int m_value;
    std::vector<Edge*> m_edges;
};

#endif  // EXAMPLES_GOLDEN_GRAPH_NODE_HPP
