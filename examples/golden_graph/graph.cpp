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

void Graph::deleteEdge(int id1, int id2) {
	Node* node1 = const_cast<Node*>(getNode(id1));
    Node* node2 = const_cast<Node*>(getNode(id2));
    
    if (!node1 || !node2) {
        std::cout << "Error: invalid node ID's" << std::endl;
        return;
    }
    
    for (auto it = node1->getEdges().begin(); it != node1->getEdges().end(); ++it) {
        Edge* edge = *it;
        if (edge->getDestinationID() == node2->getID()) {
            node1->getEdges().erase(it);
            delete edge;
            break;
        }
    }
    
    for (auto it = node2->getEdges().begin(); it != node2->getEdges().end(); ++it) {
        Edge* edge = *it;
        if (edge->getDestinationID() == node1->getID()) {
            node2->getEdges().erase(it);
            delete edge;
            break;
        }
    }
}
void addNode(int id, int value)
{
	if (m_checkID(id))
	{
		std::cout << "Your have such node: Please change your node id:" << std::endl;
		return;
	}
	m_nodes.push_back(new Node(id, value));
}	
