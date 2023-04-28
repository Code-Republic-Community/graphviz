#include "node.hpp"
#include <iostream>

<<<<<<< HEAD
Node::Node(int id, int value) : m_id (id), m_value (value) {}

void Node::setValue(int value){
	m_value = value;
}
=======
Node::Node(int id, int value) : m_ID {id}, m_value {value} {}

void Node::setValue(int value) {
	m_value = value;
}

>>>>>>> main

int Node::getID() const
{
	return m_id;
}

int Node::getValue() const
{
	return m_value;
}

<<<<<<< HEAD
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

=======
>>>>>>> main
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
<<<<<<< HEAD
		std::cout << edge->getID() << ", ";
=======
		std::cout << edge->getDestinationID() << ", ";
>>>>>>> main
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
