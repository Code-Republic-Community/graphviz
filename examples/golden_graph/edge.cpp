#include "edge.hpp"

Edge::Edge(int id_1, int id_2) : m_id_1(id_1), m_id_2(id_2) {}

void Edge::setID1(int id_1) {
    m_id_1 = id_1;
}

int Edge::getID1() const {
    return m_id_1;
}

void Edge::setID2(int id_2) {
    m_id_2 = id_2;
}

int Edge::getID2() const {
    return m_id_2;
}