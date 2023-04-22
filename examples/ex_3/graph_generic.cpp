#include <iostream>
#include <unordered_map>
#include <vector>

template <typename T>
class Graph
{
private:
    std::unordered_map<T, std::vector<T>> map;
public:
    Graph() = default;

    template <typename T_el1, typename T_el2> 
    void add_edge(T_el1&& vertex_1, T_el2&& vertex_2)
    {
        if (map.find(vertex_1) == map.end())
            map.insert(std::make_pair(vertex_1, std::vector<T>()));
        if (map.find(vertex_2) == map.end())
            map.insert(std::make_pair(vertex_2, std::vector<T>()));
        map[vertex_1].push_back(vertex_2);
        map[vertex_2].push_back(vertex_1);
    }

    template <typename T_el> 
    void add_vertex(T_el&& vertex)
    {
        map.insert(std::make_pair(vertex, std::vector<T>()));
    }

    void print_adj_list()
    {
        for (auto node : map)
        {
            std::cout << "Vertex " << node.first << " -> ";
            for (auto nbr : node.second)
            {
                std::cout << nbr << ", ";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    Graph<int> g_int;
    g_int.add_vertex(0);
    g_int.add_edge(0, 1);
    g_int.add_edge(0, 5);
    g_int.add_edge(1, 5);
    g_int.add_edge(5, 2);
    g_int.add_edge(2, 3);
    g_int.add_edge(2, 4);
    g_int.add_edge(3, 4);

    g_int.print_adj_list();

    Graph<char> g_char;
    g_char.add_edge('A', 'F');
    g_char.add_edge('B', 'F');
    g_char.add_edge('C', 'F');
    g_char.add_edge('C', 'D');
    g_char.add_edge('D', 'E');
    g_char.add_edge('E', 'F');

    g_char.print_adj_list();

    Graph<std::string> g_string;
    std::string a = "Aaa";
    std::string f = "Faa";
    g_string.add_vertex(f);
    g_string.add_vertex(f);
    g_string.add_edge(a, "Faa");
    g_string.add_edge("Baa", "Faa");
    g_string.add_edge("Caa", "Faa");
    g_string.add_edge("Caa", "Daa");
    g_string.add_edge("Daa", "Eaa");
    g_string.add_edge("Eaa", "Faa");

    g_string.print_adj_list();

}
