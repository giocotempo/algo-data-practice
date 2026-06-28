#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

std::vector<int> topological_sort(const std::vector<std::vector<std::pair<int, int>>>& graph) {
  int v = graph.size();
  std::vector<int> in_degrees(v, 0);

  for (int node = 0; node < v; node++) {
    for (const auto& [nbr, weight] : graph[node]) {
      in_degrees[nbr]++;
    }
  }

  std::vector<int> zero_degrees;
  for (int node = 0; node < v; node++) {
    if (in_degrees[node] == 0) {
      zero_degrees.push_back(node);
    }
  }

  std::vector<int> topo_order;
  while(!zero_degrees.empty()) {
    int node = zero_degrees.back();
    zero_degrees.pop_back();
    topo_order.push_back(node);

    for (const auto& [nbr, weight] : graph[node]) {
      in_degrees[nbr]--;
      if (in_degrees[nbr] == 0) {
        zero_degrees.push_back(nbr);
      }
    }
  }

  if (topo_order.size() < v) {
    return {};
  }

  return topo_order;
}

std::vector<int> dag_longest_path(const std::vector<std::vector<std::pair<int, int>>>& graph, int start) {
  std::vector<int> topo_order = topological_sort(graph);
  std::unordered_map<int, int> distances;
  distances[start] = 0;

  for (int node : topo_order) {
    if (distances.find(node) == distances.end()) continue;

    for (const auto& [nbr, weight] : graph[node]) {
      if (distances.find(nbr) == distances.end() ||
          distances[node] + weight > distances[nbr]) {
            distances[nbr] = distances[node] + weight;
          }
    }
  }

  std::vector<int> res;
  for (int node = 0; node < graph.size(); node++) {
    if (distances.find(node) == distances.end()) {
      res.push_back(std::numeric_limits<int>::min());
    } else {
      res.push_back(distances[node]);
    }
  }

  return res;
}

int main() {
    // Example
    std::vector<std::vector<std::pair<int, int>>> graph = {
        {{1, 10}},
        {},
        {{1, 10}},
        {{4, 12}},
        {{1, 11}, {2, 21}, {5, 14}},
        {{2, -30}}
    };
    int start = 4;

    std::vector<int> result = dag_longest_path(graph, start);
    std::cout << "[";
    for (int i = 0; i < result.size(); i++) {
        if (result[i] == std::numeric_limits<int>::min()) {
            std::cout << "-inf";
        } else {
            std::cout << result[i];
        }
        if (i < result.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
