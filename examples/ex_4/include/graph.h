#include <vector>
#ifndef GRAPH_H
#define GRAPH_H
#include "include/nodes.h"
#include "include/edge.h"


class Graph
{
 public:
	 Graph(int);  
 
 public:
	 void addEdge(int, int, int);
	 void addNode(int);
	 void print();

 private:
	 Node* getAdjNode(int, int, Node*);
 	 bool edgeValidation(int, int);
 
 private:
	 std::vector<Node*> m_head;
	 int m_countOfVertex;
};

#endif // graph.h
