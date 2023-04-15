#include <iostream>
#include "graph.h"

Graph::Graph(int countOfVertex)
: m_countOfVertex(countOfVertex) 
{

	for (int i = 0; i < m_countOfVertex; ++i)
	{
		m_head.push_back(new Node);
		m_head[i] = nullptr;
        }
}

bool Graph::edgeValidation(int startVertex, int endVertex)
{
	if (startVertex >= m_countOfVertex || endVertex >= m_countOfVertex)
		{
			std::cout << "Invalid argument: " << std::endl;
			return false;
		}

	return true;

}

Node* Graph::getAdjNode(int value, int weight, Node* head)
{
	Node* newNode = new Node();
	
	newNode->m_value = value;
	newNode->m_cost = weight;
	newNode->m_next = head;

	return newNode;
}

void Graph::addNode(int value)
{
	if (value < m_countOfVertex)
	{
		std::cout << "Invalid Argument: " << std::endl;
	}

	m_head.push_back(new Node());
	m_head[m_countOfVertex] = nullptr;
	++m_countOfVertex;
}

void Graph::addEdge(int startVertex, int endVertex, int weight)
{
	if (edgeValidation(startVertex,endVertex))	
	{
		Node* newNode = getAdjNode(endVertex, weight, m_head[startVertex]);

        	m_head[startVertex] = newNode;
	}

}

void Graph::print()
{
	for (int i = 0; i < m_countOfVertex; ++i)
	{
		Node* printNode = m_head[i];
		
		std::cout << " Node " << i << ":";

		while (printNode != nullptr)
		{
			if (printNode->m_cost == 0 )
			{
				std::cout << "\n        ->" << " Node " << printNode->m_value << ",";
			}
			else
			{
				std::cout << "\n        ->" << " Node " << printNode->m_value 
					  << " weigth(" << printNode->m_cost << ")" << ",";
		
				printNode = printNode->m_next;
			}
		}
		
		std::cout << std::endl;

	}
}
