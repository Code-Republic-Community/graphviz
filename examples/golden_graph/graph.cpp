#include "graph.hpp"

const Node* Graph::getNode(int id) const {
    for (const auto& node : m_nodes) {
        if (node->getID() == id) {
            return node;
        }
    }
    return nullptr;
}

const std::vector<Node*>& Graph::getAllNodes() const { return m_nodes; }

bool Graph::m_checkID(int id) {
    for (const auto& node : m_nodes) {
        if (node->getID() == id) {
            return true;
        }
    }
    return false;
}
