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

void Graph::printNodeProperties(int id) const
{
	m_getNode(id).print();
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
