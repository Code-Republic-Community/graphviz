#include "gtest/gtest.h"
#include "../examples/golden_graph/graph.hpp"
	
TEST (test_template, first_test) 
{
	Graph g;
	g.addNode(7, 8);
	Node* ptr = g.get_node(7);
	EXPECT_EQ(7, ptr->getID());
}

