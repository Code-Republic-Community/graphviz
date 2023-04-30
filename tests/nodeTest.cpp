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

TEST(test_template, first_test) {
    EXPECT_EQ(5, testValue(5));
    EXPECT_EQ(100, testGetID(100));
    EXPECT_EQ(true, testAddEdge(1));
    EXPECT_EQ(true, testGetEdges());
}