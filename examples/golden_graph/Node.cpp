#include "Node.h"

Node::Node(int id, int value)
: _id(id), _value(value)
{}

void Node::addEdge(Edge* edge)
{
	_edges.push_back(edge);
}
