#include "node.hpp"
#include "edge.hpp"
#include <vector>

Node::Node(int id, int value) : m_id {id}, m_value {value} {}

void Node::deleteThis()
{
	for (int i = 0; i < m_edges.size(); ++i)
	{
		if (m_edges[i]->get_start() != m_edges[i]->get_end)
		{
			Node* node = get_node(m_edges[i]->get_end);
			for (int j = 0; j < node.size(); ++j)
			{
				if (node -> m_edges[i]->get_start() == m_ID)
				{
					node -> m_edges.erase(j,1);
				}
			}
		}
	}
	m_edges.clear();
}
