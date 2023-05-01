#ifndef EXAMPLES_GOLDEN_GRAPH_GRAPH_HPP
#define EXAMPLES_GOLDEN_GRAPH_GRAPH_HPP

#include <iostream>
#include <vector>

#include "../../libs/json/include/nlohmann/json.hpp"  // This relative path will be modified
#include "edge.hpp"
#include "node.hpp"

using json = nlohmann::json;

class Graph {
   public:
    Graph() = default;

   public:
    const Node* getNode(int id) const;
    const std::vector<Node*>& getAllNodes() const;
    void deleteEdge(int id1, int id2);
    static void Graph::graphExport(const Graph* graph);
    void addEdge(int sourceID, int destinationID);
    void addNode(int id, int value);
    bool checkID(int id) const;
    void deleteNode(int id);
    void printNodeProperties(int id) const;

   private:
    Node* m_getNode(int id) const;

   private:
    std::vector<Node*> m_nodes;
};

#endif  // EXAMPLES_GOLDEN_GRAPH_GRAPH_HPP
