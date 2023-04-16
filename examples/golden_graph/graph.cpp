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
    return nullptr;
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

void Graph::add_edge(int id_1, int id_2)
{
	if (_checkID(id_1) && _checkID(id_2))
	{
		for (auto& node: _nodes)
		{
			if (node.get_id() == id_1)
			{
				node.add_edge(new Edge(id_1,id_2));
			}
		}
	}
	else
	{
		std::cout << "Invalid argument: " << std::endl;
	}
}
