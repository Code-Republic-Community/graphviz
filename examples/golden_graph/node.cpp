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

std::vector<Edges*>& Node::getEdges() const
{
	return m_edges;
}

void Node::print()
{
	std::cout << "\nID: " << getID()
		  << "\nValue: " << getValue()
		  << "\nEdges: " << getEdges().print() << std::endl;
}
