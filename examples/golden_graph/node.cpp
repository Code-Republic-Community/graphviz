#include "node.hpp"

Node::Node(int id, int value) : m_id {id}, m_value {value} {}

void Node::setValue(int value) {
	m_value = value;
}


int Node::getID() const
{
	return m_id;
}

int Node::getValue() const
{
	return m_value;
}

const std::vector<Edge*>& Node::getEdges() const
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
