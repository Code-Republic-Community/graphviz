#ifndef EXAMPLE_GOLDEN_GRAPH_EDGE_HPP
#define EXAMOLE_GOLDEN_GRAPH_EDGE_HPP

class Edge {
public:
    Edge(int id_1, int id_2) : _id_1(id_1), _id_2(id_2) {}
public:
    void set_id_1(int);
    int get_id_1() const;

    void set_id_2(int);
    int get_id_2() const;

private:
    int _id_1;
    int _id_2;
};

#endif //EXAMPLE_GOLDEN_GRAPH_EDGE_HPP
