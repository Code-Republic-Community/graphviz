#include "gtest/gtest.h"
#include "../examples/golden_graph/node.hpp"

#include <iostream>

const int testValue(int value) {
    Node node(1, value);
    return node.getValue();
}

const int testGetID(int id) {
    Node node(id, 5);
    return node.getID();
}

bool testAddEdge(int edgeID) {
    Node node(1, 100);
    node.addEdge(edgeID, Direction::DESTINATION);
    node.addEdge(edgeID + 1, Direction::SOURCE);
    node.addEdge(edgeID + 2, Direction::DESTINATION);
    node.addEdge(edgeID + 3, Direction::SOURCE);

    std::vector<std::pair<int, Direction>> vec {{edgeID, Direction::DESTINATION},
                                                {edgeID + 1, Direction::SOURCE},
                                                {edgeID + 2, Direction::DESTINATION},
                                                {edgeID + 3, Direction::SOURCE}};

    int i = 0;
    for (auto it = node.getEdges().begin(); it != node.getEdges().end(); ++it) {
        if ((*it)->getID() == vec[i].first && (*it)->getDirection()  == vec[i].second) {
            ++i;
            continue;
        } else {
            return false; 
        }
    }
    return true;
}

bool testGetEdges() {
    Node node(1, 100);
    node.addEdge(1, Direction::DESTINATION);
    node.addEdge(2, Direction::SOURCE);
    node.addEdge(3, Direction::SOURCE);
    node.addEdge(4, Direction::DESTINATION);

    std::vector<std::pair<int, Direction>> vec{{1, Direction::DESTINATION},
                                                {2, Direction::SOURCE},
                                                {3, Direction::SOURCE},
                                                {4, Direction::DESTINATION}};
    int i = 0;
    for (const auto& edge : vec) {
        if (edge.first == node.getEdges()[i]->getID() && edge.second == node.getEdges()[i]->getDirection()) {
            ++i;
        }
    }
    if (vec.size() != i) {
        return false;
    }
    return true;
}

const int testValue(int value) {
    Node nodeobj(1, value);
    return nodeobj.getValue();
}

const int testGetID(int id) {
    Node nodeobj(id, 5);
    return nodeobj.getID();
}

const int testSetValue(int id) {
    Node nodeobj(10,11);
    nodeobj.setValue(id);
    return nodeobj.getValue();
}

const int testDeleteEdge() {
    Node nodeobj(12,13);
    nodeobj.addEdge(1001,Direction::SOURCE);
    nodeobj.addEdge(1002,Direction::SOURCE);
    nodeobj.addEdge(1003,Direction::DESTINATION);
    nodeobj.addEdge(1004,Direction::DESTINATION);
    nodeobj.deleteEdge(1002);
    nodeobj.deleteEdge(1004);

    return nodeobj.getEdges().size();
}

TEST(test_template, first_test) {
    EXPECT_EQ(5, testValue(5));
    EXPECT_EQ(100, testGetID(100));
    EXPECT_EQ(true, testAddEdge(1));
    EXPECT_EQ(true, testGetEdges());
    EXPECT_EQ(150, testSetValue(150));
    EXPECT_EQ(2, testDeleteEdge());
}
