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
			if (node.getID() == id1)
			{
				node.addEdge(new Edge(id1, id2));
			}
		}
	}
	else
	{
		std::cout << "Invalid argument: " << std::endl;
	}

}
