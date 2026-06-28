#include <iostream>
#include <vector>
#include <map>
#include <limits>

std::vector<int> topological_sort(const std::vector<std::vector<std::pair<int, int>>>& graph) {
  int v = graph.size();
  std::vector<int> in_degrees(v, 0);

  for (int node = 0; node < v; node++) {
    for (const auto& edge : graph[node]) {
      int nbr = edge.first;
      in_degrees[nbr]++;
    }
  }

  std::vector<int> degree_zero;
  for (int node = 0; node < v; node++) {
    if (in_degrees[node] == 0) {
      degree_zero.push_back(node);
    }
  }

  std::vector<int> topo_order;
  while (!degree_zero.empty()) {
    int node = degree_zero.back();
    degree_zero.pop_back();
    topo_order.push_back(node);

    for (const auto& edge : graph[node]) {
      int nbr = edge.first;
      in_degrees[nbr]--;
      if (in_degrees[nbr] == 0) {
        degree_zero.push_back(nbr);
      }
    }
  }

  if (topo_order.size() < v) {
    return std::vector<int>();
  }

  return topo_order;
}

std::vector<double> distance(const std::vector<std::vector<std::pair<int, int>>>& graph, int start) {
  std::vector<int> topo_order = topological_sort(graph);
  std::map<int, double> distances;
  distances[start] = 0;

  for (int node : topo_order) {
    if (distances.find(node) == distances.end()) continue;

    for (const auto& edge : graph[node]) {
      int nbr = edge.first;
      int weight = edge.second;

      if (distances.find(nbr) == distances.end() || 
          distances[node] + weight < distances[nbr]) {
            distances[nbr] = distances[node] + weight;
          }
    }
  }

  std::vector<double> res;
  for (int i = 0; i < graph.size(); i++) {
    if (distances.find(i) != distances.end()) {
      res.push_back(distances[i]);
    } else {
      res.push_back(std::numeric_limits<double>::infinity());
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
    std::vector<double> result = distance(graph, start);

    for (double d : result) {
        if (d == std::numeric_limits<double>::infinity()) {
            std::cout << "inf ";
        } else {
            std::cout << d << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
