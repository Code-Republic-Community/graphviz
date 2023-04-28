#include "graph.hpp"

const Node* Graph::getNode(int id) const {
    for (const auto& node: m_nodes) {
        if (node->getID() == id) {
            return node;
        }
    }
    return nullptr;
}

const std::vector<Node*>& Graph::getAllNodes() const {
    return m_nodes;
}

bool Graph::m_checkID(int id) {
    for (const auto& node: m_nodes) {
        if (node->getID() == id) {
            return true;
        }
    }
    return false;
}

Node* Graph::m_getNode(int id) const
{
	for (auto& node : m_nodes)
	{
		if (node->getID() == id)
		{
			return node;
		}
	}

	return nullptr;
}

void Graph::addEdge(int sourceID, int destinationID)
{
	if (m_checkID(sourceID) && m_checkID(destinationID))
	{
		m_getNode(sourceID)->addEdge(destinationID, Direction::DESTINATION);
		m_getNode(destinationID)->addEdge(sourceID, Direction::SOURCE);
	}
	else
	{
		std::cout << "Invalid argument: " << std::endl;
	}

}
