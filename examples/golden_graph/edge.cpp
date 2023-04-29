#include "edge.hpp"

Edge::Edge(int id, Direction direction) : m_ID(id), m_direction(direction) {}

Direction Edge::getDirection() const {
    return m_direction;
}

int Edge::getID() const {
    return m_ID;
}
