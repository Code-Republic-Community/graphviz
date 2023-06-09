#include "graph.hpp"

#include <vector>

const Node* Graph::getNode(int id) const {
    for (const auto& node : m_nodes) {
        if (node->getID() == id) {
            return node;
        }
    }
    return nullptr;
}

const std::vector<Node*>& Graph::getAllNodes() const { return m_nodes; }

bool Graph::checkID(int id) const {
    for (const auto& node : m_nodes) {
        if (node->getID() == id) {
            return true;
        }
    }
    return false;
}

Node* Graph::m_getNode(int id) const {
    for (auto& node : m_nodes) {
        if (node->getID() == id) {
            return node;
        }
    }
    return nullptr;
}

void Graph::addEdge(int sourceID, int destinationID) {
    if (checkID(sourceID) && checkID(destinationID)) {
        m_getNode(sourceID)->addEdge(destinationID, Direction::DESTINATION);
        m_getNode(destinationID)->addEdge(sourceID, Direction::SOURCE);
    } else {
        std::cout << "Invalid argument: " << std::endl;
    }
}

void Graph::printNodeProperties(int id) const { m_getNode(id)->print(); }

void Graph::deleteEdge(int id1, int id2) {
    Node* node1 = m_getNode(id1);
    Node* node2 = m_getNode(id2);

    if (!node1 || !node2) {
        std::cout << "Error: invalid node ID's" << std::endl;
        return;
    }

    for (auto it = node1->getEdges().begin(); it != node1->getEdges().end(); ++it) {
        Edge* edge = *it;
        if (edge->getID() == node2->getID()) {
            node1->deleteEdge(id2);
            break;
        }
    }

    for (auto it = node2->getEdges().begin(); it != node2->getEdges().end(); ++it) {
        Edge* edge = *it;
        if (edge->getID() == node1->getID()) {
            node2->deleteEdge(id1);
            break;
        }
    }
}

void Graph::graphExport(const Graph* graph) {
    // create integer to hold index of graph
    static int indexOfGraph = 1;

    // create the jsonGraph object
    json jsonGraph;
    jsonGraph["node"] = json::array();
    const auto nodes = graph->getAllNodes();
    for (const auto& node : nodes) {
        jsonGraph["node"].push_back(node->getID());
    }

    // create jsonNode objects for the graph
    for (const auto& node : nodes) {
        json jsonNode;
        jsonNode["value"] = node->getValue();
        jsonNode["neighbors"] = json::array();

        // add each neighbor to the jsonNode object
        const auto edges = node->getEdges();
        for (const auto& edge : edges) {
            jsonNode["neighbors"].push_back(edge->getID());
        }
        // add the jsonNode object to the graph object
        jsonGraph[node->getID()] = jsonNode;
    }

    // Add name of graph. Example graph_1, graph_2, ...
    jsonGraph["name"] = "graph_" + std::to_string(indexOfGraph);
    ++indexOfGraph;

    // write the JSON object to a file
    std::ofstream file("export.json", std::ios::app);
    file << jsonGraph.dump(4);  // pretty print with 4 spaces
    file.close();
}

void Graph::addNode(int id, int value) {
    if (checkID(id)) {
        std::cout << "Your have such node: Please change your node id:" << std::endl;
        return;
    }
    m_nodes.push_back(new Node(id, value));
}

void Graph::deleteNode(int id) {
    if (!checkID(id)) {
        std::cout << "wrong id";
        return;
    }
    Node* node = m_getNode(id);
    auto edges = node->getEdges();
    std::vector<int> deleteIDs;
    for (int i = 0; i < node->getEdges().size(); ++i) {
        deleteIDs.emplace_back(edges[i]->getID());
    }
    for (int i = 0; i < deleteIDs.size(); ++i) {
        deleteEdge(id, deleteIDs[i]);
    }
    delete node;
}