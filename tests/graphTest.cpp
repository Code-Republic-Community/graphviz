#include "gtest/gtest.h"
#include "../examples/golden_graph/graph.hpp"

bool addEdgeCheck(int id1, int id2) {
    Graph graph;
    // Adding two nodes
    graph.addNode(id1, 12);
    graph.addNode(id2, 5);
    // Adding one edge between two nodes 
    graph.addEdge(id1, id2);
    // Getting nodes from graph
    const Node* node1 = graph.getNode(id1);
    const Node* node2 = graph.getNode(id2);
    // Getting edges vector of each node
    std::vector<Edge*> edges1 = node1->getEdges();
    std::vector<Edge*> edges2 = node2->getEdges();
    // Checking if in the node1's edges vector has edge object with node2's id (first find_if)
    // Checking if in the node2's edges vector has edge object with node1's id (second find_if)
    if (std::find_if(edges1.begin(), edges1.end(), [id2](Edge* edge){
                                                        return edge->getID() == id2;
                                                    }) != edges1.end()
        &&
        std::find_if(edges2.begin(), edges2.end(), [id1](Edge* edge){
                                                        return edge->getID() == id1;
                                                    }) != edges2.end() )
        return true;
    return false;
}

bool deleteEdgeCheck(int id1, int id2) {
    Graph graph;
    // Adding some nodes
    graph.addNode(id1, 12);
    graph.addNode(id2, 5);
    graph.addNode(7, 12);
    graph.addNode(9, 5);
    // Adding edges between nodes
    graph.addEdge(id1, id2);
    graph.addEdge(7, 9);
    // Deleting that edge between two nodes
    graph.deleteEdge(id1, id2);    
    // Getting nodes from graph
    const Node* node1 = graph.getNode(id1);
    const Node* node2 = graph.getNode(id2);
    // Getting edges vector of each node
    std::vector<Edge*> edges1 = node1->getEdges();
    std::vector<Edge*> edges2 = node2->getEdges();
    // Checking if in the node1's edges vector hasn't edge object with node2's id (first find_if)
    // Checking if in the node2's edges vector hasn't edge object with node1's id (second find_if)
    if (std::find_if(edges1.begin(), edges1.end(), [id2](Edge* edge) {
                                                        return edge->getID() == id2;
                                                    }) == edges1.end()
        &&
        std::find_if(edges2.begin(), edges2.end(), [id1](Edge* edge) {
                                                        return edge->getID() == id1;
                                                    }) == edges2.end() )
        return true;
    return false;
}

TEST(test_template, first_test) {
    EXPECT_EQ(true, addEdgeCheck(2,3));
    EXPECT_EQ(true, deleteEdgeCheck(2,3));
}
