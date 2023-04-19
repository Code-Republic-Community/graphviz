#include "Node.hpp"

Node::Node(int id, int value)
{
	m_id = id;
	m_value = value;
}

void Node::delete_this()
{
	m_edges.empty();	
}

