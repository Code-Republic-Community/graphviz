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

static void Graph::graphExport(const Graph* graph) {
	// create integer to hold index of graph
	static int indexOfGraph = 1;
	
	// create the jsonGraph object
	json jsonGraph;
	jsonGraph["node"] = json::array();
	const auto nodes = graph->getAllNodes();
	for (const auto& node : nodes) {
		jsonGraph["node"].push_back(node->getID());
	}

	// create jsonNode objects for the first graph
	for (const auto& node : nodes) {
		json jsonNode;
		jsonNode["value"] = node->getValue();
		jsonNode["neighbors"] = json::array();

		// add each neighbor to the jsonNode object
		const auto edges = node->getEdges();
		for (const auto& edge : edges) {
			jsonNode["neighbors"].push_back(edge->getDestinationID());
		}
		// add the jsonNode object to the graph object
		jsonGraph[node->getID()] = jsonNode;
	}

	// Add name of graph. Example graph_1, graph_2, ...
	jsonGraph["name"] = "graph_" + std::to_string(indexOfGraph);
	++indexOfGraph;

    // write the JSON object to a file
    std::ofstream file("export.json", std::ios::app);
    file << jsonGraph.dump(4); // pretty print with 4 spaces
    file.close();
}
