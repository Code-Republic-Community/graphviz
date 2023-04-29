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

bool Graph::checkID(int id) const {
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

void addNode(int id, int value)
{
	if (m_checkID(id))
	{
		std::cout << "Your have such node: Please change your node id:" << std::endl;
		return;
	}
	m_nodes.push_back(new Node(id, value));
}	

void deleteNode(int id)
{
	if (!checkID(id))
	{
		std::cout << "wrong id";
		return ;
	}
	Node* node = get_node(id);
	for (int i = 0; i < node -> m_edges.size(); ++i)
	{
		node -> m_edges[i] -> deleteEdge(m_edges[i].get_ID());
	}
}	
