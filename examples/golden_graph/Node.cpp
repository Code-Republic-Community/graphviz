#include "Node.h"

Node::Node(int id, int value)
: _id(id), _value(value)
{}

void Node::get_id() const
{
	return _id;
}

void Node::get_value() const
{
	return _value;
}

void Node::add_edge(Edge* edge)
{
	_edges.push_back(edge);
}
