#include "node.hpp"

Node::Node(int id, int value) : m_ID {id}, m_value {value} {}

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
