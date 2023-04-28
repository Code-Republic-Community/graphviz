#ifndef EXAMPLE_GOLDEN_GRAPH_EDGE_HPP
#define EXAMPLE_GOLDEN_GRAPH_EDGE_HPP
#include <stdint.h>

enum class Direction : int16_t {
	DESTINATION,
	SOURCE
};

class Edge {
public:
    Edge(int id, Direction direction);

public:
    Direction getDirection() const;
    int getID() const;

private:
    Direction m_direction;
    int m_ID;
};

#endif //EXAMPLE_GOLDEN_GRAPH_EDGE_HPP
