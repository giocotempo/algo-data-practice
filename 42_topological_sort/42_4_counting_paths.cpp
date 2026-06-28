#include <iostream>
#include <vector>
#include <map>

std::vector<int> topological_sort(const std::vector<std::vector<int>>& graph) {
  int v = graph.size();

  std::vector<int> in_degrees(v, 0);
  for (int node = 0; node < v; node++) {
    for (int nbr : graph[node]) {
      in_degrees[nbr]++;
    }
  }

  std::vector<int> zero_degree;
  for (int node = 0; node < v; node++) {
    if (in_degrees[node] == 0) {
      zero_degree.push_back(node);
    }
  }

  std::vector<int> topo_order;
  while (!zero_degree.empty()) {
    int node = zero_degree.back();
    zero_degree.pop_back();
    topo_order.push_back(node);
    
    for (int nbr : graph[node]) {
      in_degrees[nbr]--;
      if (in_degrees[nbr] == 0) {
        zero_degree.push_back(nbr);
      }
    }
  }

  if (topo_order.size() < v) {
    return std::vector<int>();
  }

  return topo_order;
}

std::vector<int> counting_paths(const std::vector<std::vector<int>>& graph, int start) {
  std::vector<int> topo_order = topological_sort(graph);
  std::map<int, int> counts;
  counts[start] = 1;

  for (int node : topo_order) {
    if (counts.find(node) == counts.end()) continue;

    for (int nbr : graph[node]) {
      if (counts.find(nbr) == counts.end()) {
        counts[nbr] = counts[node];
      } else {
        counts[nbr] += counts[node];
      }
    }
  }

  std::vector<int> res;
  for (int node = 0; node < graph.size(); node++) {
    if (counts.find(node) == counts.end()) {
      res.push_back(0);
    } else {
      res.push_back(counts[node]);
    }
  }

  return res;
}

int main() {
    // Example
    std::vector<std::vector<int>> graph = {
        {1},
        {},
        {1},
        {4},
        {1, 2, 5},
        {2}
    };
    int start = 4;

    std::vector<int> result = counting_paths(graph, start);

    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
