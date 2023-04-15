#ifndef EXAMPLES_GOLDEN_GRAPH_GRAPH_HPP
#define EXAMPLES_GOLDEN_GRAPH_GRAPH_HPP

#include <vector>

class Graph
{
private:
    bool _checkID(int id);
    std::vector<Node*> _nodes;
public:
    Graph() = default;
    const Node* get_node(int id) const;
};

#endif //EXAMPLES_GOLDEN_GRAPH_GRAPH_HPP
