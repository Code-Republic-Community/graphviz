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

void Graph::addEdge(int id1, int id2)
{
	if (m_checkID(id1) && m_checkID(id2))
	{
		for (auto& node : m_nodes)
		{
			if (node->getID() == id1)
			{
				addEdge(new Edge(id1, id2));
			}
		}
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
