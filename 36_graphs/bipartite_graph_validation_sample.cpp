#include <iostream>
#include <unordered_map>
#include <vector>

void dfs(const std::vector<std::vector<int>>& graph,
         std::unordered_map<int, int>& visited,
         int node,
         int color,
         int& conflict) {
    if (visited.find(node) != visited.end()) {
        if (visited[node] != color) {
            conflict += 1;
        }
        return;
    }

    visited[node] = color;

    for (int neighbor : graph[node]) {
        dfs(graph, visited, neighbor, -color, conflict);
    }
}

bool bipartite_graph_validation(const std::vector<std::vector<int>>& graph) {
    std::unordered_map<int, int> visited;
    int conflict = 0;

    dfs(graph, visited, 0, 1, conflict);
    return conflict == 0;
}

int main() {
    // Example1
    std::vector<std::vector<int>> graph1 = {
        {1, 4},
        {0, 2},
        {1},
        {4},
        {0, 3}
    };
    std::cout << (bipartite_graph_validation(graph1) ? "true" : "false") << std::endl;

    // Example2
    std::vector<std::vector<int>> graph2 = {
        {1, 2, 4},
        {0, 2},
        {0, 1},
        {4},
        {0, 3}
    };
    std::cout << (bipartite_graph_validation(graph2) ? "true" : "false") << std::endl;

    return 0;
}
