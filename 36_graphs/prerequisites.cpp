#include <iostream>
#include <vector>

std::vector<std::vector<int>> make_adjacent_list(
    int n,
    const std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> graph(n);

        for (const std::vector<int>& prerequisite : prerequisites) {
            const int start = prerequisite[0];
            const int end = prerequisite[1];
            graph[start].push_back(end);
        }

        return graph;
}

std::vector<int> topological_sort(
    const std::vector<std::vector<int>>& graph) {
        std::vector<int> in_degrees(graph.size(), 0);

        for (const std::vector<int>& nbrs : graph) {
            for (int nbr : nbrs) {
                in_degrees[nbr] += 1;
            }
        }

        std::vector<int> zero_degree;
        for (int node = 0; node < static_cast<int>(graph.size()); node++) {
            if (in_degrees[node] == 0) {
                zero_degree.push_back(node);
            }
        }

        std::vector<int> topo_order;
        while (!zero_degree.empty()) {
            const int node = zero_degree.back();
            zero_degree.pop_back();
            topo_order.push_back(node);

            for (int nbr : graph[node]) {
                in_degrees[nbr] -= 1;
                if (in_degrees[nbr] == 0) {
                    zero_degree.push_back(nbr);
                }
            }
        }

        return topo_order;
}

bool determine_prerequisites(
    int n,
    const std::vector<std::vector<int>>& prerequisites) {
        const std::vector<std::vector<int>> graph = make_adjacent_list(n, prerequisites);
        const std::vector<int> topo_order = topological_sort(graph);
        return topo_order.size() == static_cast<std::size_t>(n);
}

int main() {
    // Example1
    int n = 3;
    std::vector<std::vector<int>> prerequisites = {
        {0, 1},
        {1, 2},
        {2, 1},
    };
    std::cout << (determine_prerequisites(n, prerequisites)
                      ? "true"
                      : "false")
              << std::endl;

    // Example2
    n = 5;
    prerequisites = {
        {0, 1},
        {1, 2},
        {2, 4},
        {4, 3},
    };
    std::cout << (determine_prerequisites(n, prerequisites)
                      ? "true"
                      : "false")
              << std::endl;

    return 0;
}
