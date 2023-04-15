#include <iostream>
#include <vector>
#include <exception>

class Edge
{
public:
	Edge(const int start, const int end, const int weight)
	{
		_start = start;
		_end = end;
		_weight = weight;
	}
private:	
	int _start;
	int _end;
	int _weight;
};

class Node 
{
public:
	Node(const int Id, const int num)
	{
		_num = num;
		_id = Id;
		
	}
public:
	void set_edge(const int start, const int end, const int weight)
	{
		Edge edge(start, end, weight);
		_edges.push_back(edge);
	}
	int get_num() const
	{
		return _num;
	}
	void cout()
	{	
	
	}
private:
	int _num;
	std::vector<Edge> _edges;
};

class Graph
{
public:
	bool has_nod(const int num)
	{
		for (int i = 0; i < _nodes.size(); ++i)
		{
			if(_nodes[i].get_num() == num)
			{
				return true;		
			}
		}
		return false;
	}
//---------------------------------------------------------------
	void add_nod(const int id, const int value)
	{
		if (has_nod(num))//cheekId(id)
		{
			throw std::logic_error("error");
		}	
		Node node(id, value);
		_nodes.push_back(node);
	}
//---------------------------------------------------------------
	void add_edge(const int start, const int end, int weight = 0)
	{
		if (!has_nod(start) || !has_nod(end))
		{
			throw std::logic_error("error");
		}
		for (int i = 0; i < _nodes.size(); ++i)
		{
			if (_nodes[i].get_num() == start)
			{
				_nodes[i].set_edge(start, end, weight);
			}
		}
	}
	void print_node_property(const int prorp)
	{
		
private:
	std::vector<Node*> _nodes;
};

int main()
{
	Graph graph;
	graph.add_nod(1);
	graph.add_nod(2);
	graph.add_nod(3);
}
