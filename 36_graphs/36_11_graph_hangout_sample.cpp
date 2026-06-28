#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <limits>

int graph_hangout(const std::vector<std::vector<int>>& graph, int node1, int node2, int node3) {
    auto calc_distance = [&](int start) -> std::unordered_map<int, int> {
        std::queue<std::pair<int, int>> q;
        q.push({start, 0}); // start_node, distance
        std::unordered_map<int, int> number_of_edges;

        while (!q.empty()) {
            int node = q.front().first;
            int distance = q.front().second;
            q.pop();

            if (number_of_edges.find(node) != number_of_edges.end()) {
                number_of_edges[node] = std::min(number_of_edges[node], distance);
            } else {
                number_of_edges[node] = distance;
            }

            for (int nei : graph[node]) {
                if (number_of_edges.find(nei) == number_of_edges.end()) {
                    q.push({nei, distance + 1});
                } else if (number_of_edges[nei] > distance + 1) {
                    q.push({nei, distance + 1});
                }
            }
        }

        return number_of_edges;
    };

    std::unordered_map<int, std::unordered_map<int, int>> distances;
    std::vector<int> starts = {node1, node2, node3};
    for (int start : starts) {
        distances[start] = calc_distance(start);
    }

    double min_total_number_of_edge = 1e13;
    for (int node = 0; node < graph.size(); node++) {
        int total_number_of_edge = distances[node1][node] + distances[node2][node] + distances[node3][node];
        min_total_number_of_edge = std::min(min_total_number_of_edge, (double)total_number_of_edge);
    }

    return (int)min_total_number_of_edge;
}

int main() {
    // Example1
    std::vector<std::vector<int>> graph1 = {
        {1, 4},   // Node 0
        {0, 2},   // Node 1
        {1, 3},   // Node 2
        {2, 4},   // Node 3
        {0, 3}    // Node 4
    };
    int node1 = 0;
    int node2 = 2;
    int node3 = 4;
    std::cout << graph_hangout(graph1, node1, node2, node3) << std::endl;

    // Example2
    std::vector<std::vector<int>> graph2 = {
        {1, 2, 3},  // Node 0
        {0, 2, 3},  // Node 1
        {0, 1, 3},  // Node 2
        {0, 1, 2}   // Node 3
    };
    node1 = 0;
    node2 = 1;
    node3 = 2;
    std::cout << graph_hangout(graph2, node1, node2, node3) << std::endl;

    return 0;
}
