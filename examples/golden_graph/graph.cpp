#include "graph.hpp"

const Node* Graph::get_node(int id)
{
    for (const auto& node: _nodes)
    {
        if (node->_id == id)
        {
            return node;
        }
    }
}

bool Graph::_checkID(int id)
{
    for (const auto& node: _nodes)
    {
        if (node->_id == id)
        {
            return true;
        }
    }
    return false;
}
