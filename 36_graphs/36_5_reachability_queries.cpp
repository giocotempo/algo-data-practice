#include <iostream>
#include <vector>
#include <set>
#include <map>

void dfs(const std::vector<std::vector<int>>& graph, int cc_id, int node, std::set<int>& visited, std::map<int, int>& node_to_cc) {
  visited.insert(node);
  node_to_cc[node] = cc_id;
  for (size_t i = 0; i < graph[node].size(); i++) {
    int nei = graph[node][i];
    if (visited.find(nei) == visited.end()) {
      dfs(graph, cc_id, nei, visited, node_to_cc);
    }
  }
}

std::vector<bool> reachability_queries(const std::vector<std::vector<int>>& graph, const std::vector<std::pair<int, int>>& queries) {
  std::set<int> visited;
  std::map<int, int> node_to_cc;

  int cc_id = 0;
  for (int node = 0; node < graph.size(); node++) {
    if (visited.find(node) == visited.end()) {
      dfs(graph, cc_id, node, visited, node_to_cc);
      cc_id++;
    }
  }
  
  std::vector<bool> output;
  for (std::vector<std::pair<int, int>>::const_iterator it = queries.begin(); it != queries.end(); ++it) {
    output.push_back(node_to_cc[it->first] == node_to_cc[it->second]);
  }

  return output;
}

int main() {
    std::vector<std::vector<int> > graph;
    graph.push_back(std::vector<int>(1, 1));
    int arr1[] = {0, 2, 5, 4};
    graph.push_back(std::vector<int>(arr1, arr1 + 4));
    int arr2[] = {1, 4, 5};
    graph.push_back(std::vector<int>(arr2, arr2 + 3));
    graph.push_back(std::vector<int>());
    int arr3[] = {5, 2, 1};
    graph.push_back(std::vector<int>(arr3, arr3 + 3));
    int arr4[] = {1, 2, 4};
    graph.push_back(std::vector<int>(arr4, arr4 + 3));

    std::vector<std::pair<int, int> > queries;
    queries.push_back(std::make_pair(0, 4));
    queries.push_back(std::make_pair(0, 3));

    std::vector<bool> result = reachability_queries(graph, queries);

    std::cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << (result[i] ? "true" : "false");
        if (i < result.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
