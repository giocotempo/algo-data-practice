#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<int> topological_sort(const std::vector<std::vector<std::pair<int, int>>>& graph) {
    // create degrees list
    int v = graph.size();
    std::vector<int> in_degrees(v, 0);
    for (int node = 0; node < v; node++) {
        for (const auto& edge : graph[node]) {
            int nbr = edge.first;
            in_degrees[nbr]++;
        }
    }

    // create zero_degree list
    std::vector<int> degree_zero;
    for (int node = 0; node < v; node++) {
        if (in_degrees[node] == 0) {
            degree_zero.push_back(node);
        }
    }

    // create topological sort
    std::vector<int> topo_sort;
    while (!degree_zero.empty()) {
        int node = degree_zero.back();
        degree_zero.pop_back();
        topo_sort.push_back(node);
        for (const auto& edge : graph[node]) {
            int nbr = edge.first;
            in_degrees[nbr]--;
            if (in_degrees[nbr] == 0) {
                degree_zero.push_back(nbr);
            }
        }
    }

    if (topo_sort.size() < v) {
        return std::vector<int>();
    }

    return topo_sort;
}

std::vector<int> shortest_path(const std::vector<std::vector<std::pair<int, int>>>& graph, int start, int goal) {
    std::vector<int> topo_order = topological_sort(graph);
    std::unordered_map<int, int> distances;
    std::unordered_map<int, int> predecessors;
    distances[start] = 0;

    for (int node : topo_order) {
        if (distances.find(node) == distances.end()) continue;
        for (const auto& edge : graph[node]) {
            int nbr = edge.first;
            int weight = edge.second;
            if (distances.find(nbr) == distances.end() || distances[node] + weight < distances[nbr]) {
                distances[nbr] = distances[node] + weight;
                predecessors[nbr] = node;
            }
        }
    }

    if (distances.find(goal) == distances.end()) {
        return std::vector<int>();
    }

    std::vector<int> path;
    path.push_back(goal);
    while (path.back() != start) {
        path.push_back(predecessors[path.back()]);
    }

    std::reverse(path.begin(), path.end());

    return path;
}

int main() {
    // Example
    std::vector<std::vector<std::pair<int, int>>> graph = {
        {{1, 10}},           // node 0
        {},                  // node 1
        {{1, 10}},           // node 2
        {{4, 12}},           // node 3
        {{1, 11}, {2, 21}, {5, 14}},  // node 4
        {{2, -30}}           // node 5
    };
    int start = 4;
    int goal = 1;

    std::vector<int> path = shortest_path(graph, start, goal);

    std::cout << "[";
    for (size_t i = 0; i < path.size(); i++) {
        std::cout << path[i];
        if (i < path.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
