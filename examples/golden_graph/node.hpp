#ifndef EXAMPLES_GOLDEN_GRAPH_NODE_HPP
#define EXAMPLES_GOLDEN_GRAPH_NODE_HPP

#include "edge.hpp"

#include <vector>

class Node
{
public:
	Node(int id, int value);
public:
	void deleteThis();	
private:
	int m_id;
	int m_value;
	std::vector<Edge*> m_edges;
};

#endif // EXAMPLES_GOLDEN_GRAPH_NODE_HPP

