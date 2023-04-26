#include "node.hpp"
#include "edge.hpp"
#include <vector>

Node::Node(int id, int value) : m_id {id}, m_value {value} {}

<<<<<<< HEAD
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
=======
int Node::getID() const
{
	return m_id;
}

int Node::getValue() const
{
	return m_value;
}

const std::vector<Edges*>& Node::getEdges() const
{
	return m_edges;
}

void Node::print() const
{
	std::cout << "\nID: " << getID()
		  << "\nValue: " << getValue()
		  << "\nEdges: " << "[";
	for (auto& edge : m_edges)
	{
		std::cout << edge.getDestinationID() << ", ";
	}
	
	std::cout << "]" << std::endl;
>>>>>>> main
}
