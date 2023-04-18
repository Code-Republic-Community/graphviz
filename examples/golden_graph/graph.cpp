#include "graph.hpp"

const Node* Graph::get_node(int id) {
    for (const auto& node: m_nodes) {
        if (node->_id == id) {
            return node;
        }
    }
    return nullptr;
}

const std::vector<Node*>& getAllNodes() {
    return m_nodes;
}

bool Graph::_checkID(int id) {
    for (const auto& node: m_nodes) {
        if (node->_id == id) {
            return true;
        }
    }
    return false;
}
