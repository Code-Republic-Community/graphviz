#include "node.hpp"

Node::Node(int id, int value) : m_id {id}, m_value {value} {}

int Node::getID() const
{
	return m_id;
}

int Node::getValue() const
{
	return m_value;
}

void Node::addEdge(int destinationID)
{
	for (auto& edge : m_edges)
	{
		if (edge->getDestinationID() == destinationID)
		{
			std::cout << "Edge already exists: " << std::endl;
			return;
		}
	}
	
	m_edges.push_back(new Edge(destinationID));
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
		std::cout << edge->getDestinationID() << ", ";
	}
	
	std::cout << "]" << std::endl;
}
