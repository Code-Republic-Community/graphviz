#include "gtest/gtest.h"
#include "../examples/golden_graph/node.hpp"

const int testValue(int value) {
    Node nodeobj(1, value);
    return nodeobj.getValue();
}

const int testGetID(int id) {
    Node nodeobj(id, 5);
    return nodeobj.getID();
}

TEST(test_template, first_test) {
    EXPECT_EQ(5, testValue(5));
    EXPECT_EQ(100, testGetID(100));
}