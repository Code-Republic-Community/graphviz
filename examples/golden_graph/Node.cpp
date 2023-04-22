#include "Node.hpp"
#include <vector>

Node::Node(int id, int value)
{
	m_id = id;
	m_value = value;
}

void Node::delete_this()
{
	for (int i = 0; i < m_edges.size(); ++i)
	{
		if (m_id != m_edges[i] -> getDestinationID())
		{
	
		}
	}	
}

