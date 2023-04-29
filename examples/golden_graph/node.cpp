#include "node.hpp"

#include <iostream>

Node::Node(int id, int value) : m_ID (id), m_value (value) {}

void Node::setValue(int value) {
	m_value = value;
}

int Node::getID() const
{
	return m_ID;
}

int Node::getValue() const
{
	return m_value;
}

void Node::addEdge(int id, Direction direction)
{
	for (auto& edge : m_edges)
	{
		if (edge->getID() == id)
		{
			std::cout << "Edge already exists: " << std::endl;
			return;
		}
	}
	
	m_edges.push_back(new Edge(id, direction));
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
		std::cout << edge->getID() << ", ";
	}
	
	std::cout << "]" << std::endl;
}

void Node::deleteEdge(int edgeID) {
	for(auto it = m_edges.begin(); it != m_edges.end(); ++it) {
		if((*it)->getID() == edgeID) {
			delete *it;
			m_edges.erase(it);
			break;
		}
	}
}
