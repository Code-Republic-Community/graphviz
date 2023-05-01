#include "../examples/golden_graph/node.hpp"
#include "gtest/gtest.h"

const int testValue(int value) {
    Node nodeobj(1, value);
    return nodeobj.getValue();
}

const int testGetID(int id) {
    Node nodeobj(id, 5);
    return nodeobj.getID();
}

const int testSetValue(int id) {
    Node nodeobj(10, 11);
    nodeobj.setValue(id);
    return nodeobj.getValue();
}

const int testDeleteEdge() {
    Node nodeobj(12, 13);
    nodeobj.addEdge(1001, Direction::SOURCE);
    nodeobj.addEdge(1002, Direction::SOURCE);
    nodeobj.addEdge(1003, Direction::DESTINATION);
    nodeobj.addEdge(1004, Direction::DESTINATION);
    nodeobj.deleteEdge(1002);
    nodeobj.deleteEdge(1004);

    return nodeobj.getEdges().size();
}

TEST(test_template, first_test) {
    EXPECT_EQ(5, testValue(5));
    EXPECT_EQ(100, testGetID(100));
    EXPECT_EQ(150, testSetValue(150));
    EXPECT_EQ(2, testDeleteEdge());
}
