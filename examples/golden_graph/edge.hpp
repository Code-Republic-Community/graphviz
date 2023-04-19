#ifndef EXAMPLE_GOLDEN_GRAPH_EDGE_HPP
#define EXAMOLE_GOLDEN_GRAPH_EDGE_HPP

class Edge {
public:
    Edge(int id_1, int id_2);

public:
    void setID1(int id_1);
    int getID1() const;

    void setID2(int id_2);
    int getID2() const;

private:
    int m_id_1;
    int m_id_2;
};

#endif //EXAMPLE_GOLDEN_GRAPH_EDGE_HPP
