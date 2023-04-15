#ifndef Node_h
#define Node_h

#include <vector>
#include "Edge.h"

class Node
{
public:
	Node(const int, const int);
public:
	void delete_this();	
private:
	int _id;
	int _value;
	std::vector<Edge*> _edges;
};

#endif // Node_h
