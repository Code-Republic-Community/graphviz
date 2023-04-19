#ifndef EXAMPLES_GOLDEN_GRAPH_NODE_HPP
#define EXAMPLES_GOLDEN_GRAPH_NODE_HPP

#include "Edge.hpp"

#include <vector>

class Node
{
public:
	Node(int, int);
public:
	void delete_this();	
private:
	int m_id;
	int m_value;
	std::vector<Edge*> m_edges;
};

#endif // NODE_HPP
