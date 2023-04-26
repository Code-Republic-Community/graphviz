#include "edge.hpp"

Edge::Edge(int destinationID) : m_destinationID(destinationID) {}

void Edge::setDestinationID(int destinationID) {
    m_destinationID = destinationID;
}

int Edge::getDestinationID() const {
    return m_destinationID;
}