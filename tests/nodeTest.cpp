#include "gtest/gtest.h"
#include "../examples/golden_graph/node.hpp"

#include <iostream>

const int testGetValue(int value) {
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

const int testSetValue(int id) {
    Node node(10,11);
    node.setValue(id);
    return node.getValue();
}

const int testDeleteEdge() {
    Node node(12,13);
    node.addEdge(1001,Direction::SOURCE);
    node.addEdge(1002,Direction::SOURCE);
    node.addEdge(1003,Direction::DESTINATION);
    node.addEdge(1004,Direction::DESTINATION);
    node.deleteEdge(1002);
    node.deleteEdge(1004);

    return node.getEdges().size();
}

TEST(test_template, first_test) {
    EXPECT_EQ(5, testGetValue(5));
    EXPECT_EQ(100, testGetID(100));
    EXPECT_EQ(true, testAddEdge(1));
    EXPECT_EQ(true, testGetEdges());
    EXPECT_EQ(150, testSetValue(150));
    EXPECT_EQ(2, testDeleteEdge());
}
