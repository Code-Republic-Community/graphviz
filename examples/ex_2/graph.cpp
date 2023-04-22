#include <iostream>
#include <vector>
#include <unordered_map>


class Node {
public:
    int val;
    char name;
    std::vector<Node*> neighbors;
    Node(int v, char n) : val(v), name(n) {}
};

class Graph {
public:
    void addEdge(char u_name, char v_name, int u_val, int v_val) {
        if (!nodes.count(u_name)) {
            nodes[u_name] = new Node(u_val, u_name);
        }
        if (!nodes.count(v_name)) {
            nodes[v_name] = new Node(v_val, v_name);
        }
        nodes[u_name]->neighbors.push_back(nodes[v_name]);
        nodes[v_name]->neighbors.push_back(nodes[u_name]);
    }
    void printGraph() {
        for (auto it : nodes) {
            std::cout << it.first << " (value: " << it.second->val << ") -> ";
            for (Node* neighbor : it.second->neighbors) {
                std::cout << neighbor->name << " (value: " << neighbor->val << ") ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::unordered_map<char, Node*> nodes;
};

int main() {
    Graph g;
    g.addEdge('A', 'B', 1, 2);
    g.addEdge('B', 'C', 2, 3);
    g.addEdge('A', 'D', 1, 4);
    g.addEdge('D', 'E', 4, 5);
    g.addEdge('E', 'C', 5, 3);
    g.addEdge('B', 'E', 2, 5);
    g.addEdge('B', 'D', 2, 4);
    g.printGraph();
    return 0;
}

