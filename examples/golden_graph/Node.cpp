#include "Node.h"

Node::Node(const int id, const int value)
{
	_id = id;
	_value = value;
}

void Node::delete_this()
{
	m_edges.empty();	
}

