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
	int getID() const;
	int getValue() const;
	const std::vector<Edges*>& getEdges() const;
	void print() const;
	void deleteEdge(int edgeID);
private:
	int m_ID;
	int m_value;
	std::vector<Edge*> m_edges;
};

#endif // EXAMPLES_GOLDEN_GRAPH_NODE_HPP

