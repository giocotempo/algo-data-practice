#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <algorithm>

void dfs(const std::vector<std::vector<int>>& graph, std::unordered_set<int>& visited,
         std::unordered_map<int, int>& predecessors, int node) {
    for (int nei : graph[node]) {
        if (visited.find(nei) == visited.end()) {
            visited.insert(nei);
            predecessors[nei] = node;
            dfs(graph, visited, predecessors, nei);
        }
    }
}

std::vector<int> graph_path(const std::vector<std::vector<int>>& graph, int node1, int node2) {
    std::unordered_map<int, int> predecessors;
    std::unordered_set<int> visited;
    dfs(graph, visited, predecessors, node1);

    if (predecessors.find(node2) != predecessors.end()) {
        std::deque<int> d;
        d.push_front(node2);
        int dst = node2;
        while (dst != node1) {
            d.push_front(predecessors[dst]);
            dst = predecessors[dst];
        }
        return std::vector<int>(d.begin(), d.end());
    } else {
        return std::vector<int>();
    }
}

int main() {
    std::vector<std::vector<int>> graph = {
        {1},
        {0, 2, 5, 4},
        {1, 4, 5},
        {},
        {5, 2, 1},
        {1, 2, 4}
    };

    // Example1
    int node1 = 0;
    int node2 = 4;
    std::vector<int> path1 = graph_path(graph, node1, node2);
    std::cout << "[";
    for (size_t i = 0; i < path1.size(); i++) {
        std::cout << path1[i];
        if (i < path1.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    // Example2
    node1 = 0;
    node2 = 3;
    std::vector<int> path2 = graph_path(graph, node1, node2);
    std::cout << "[";
    for (size_t i = 0; i < path2.size(); i++) {
        std::cout << path2[i];
        if (i < path2.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
