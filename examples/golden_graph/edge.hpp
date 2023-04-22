#ifndef EXAMPLE_GOLDEN_GRAPH_EDGE_HPP
#define EXAMOLE_GOLDEN_GRAPH_EDGE_HPP

class Edge {
public:
    Edge(int destinationID);

public:
    void setDestinationID(int destinationID);
    int getDestinationID() const;

private:
    int m_destinationID;
};

#endif //EXAMPLE_GOLDEN_GRAPH_EDGE_HPP
