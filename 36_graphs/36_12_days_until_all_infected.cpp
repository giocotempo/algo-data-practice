#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

int days_until_all_infected(std::vector<std::vector<int>>& graph, std::vector<int>& infected) {
  std::queue<std::pair<int, int>> queue;
  std::unordered_map<int, int> infected_map;

  for (int node : infected) {
    infected_map[node] = 0;
    queue.push({node, 0});
  }
  
  while(!queue.empty()) {
    std::pair<int, int> current = queue.front();
    queue.pop();
    int node = current.first;
    int days = current.second;

    for (int nei : graph[node]) {
      if (infected_map.find(nei) == infected_map.end()) {
        infected_map[nei] = days + 1;
        queue.push({nei, days + 1});
      }
    }
  }

  int max_days = 0;
  for (const auto& pair : infected_map) {
    if (pair.second > max_days) {
      max_days = pair.second;
    }
  }

  return max_days;
}

int main() {
    // Example1
    std::vector<std::vector<int>> graph1 = {
        {1, 2},
        {0, 2},
        {0, 1, 3},
        {2}
    };
    std::vector<int> infected1 = {0};
    std::cout << days_until_all_infected(graph1, infected1) << std::endl; // Output: 2

    // Example2
    std::vector<std::vector<int>> graph2 = {
        {1},
        {0, 2},
        {1, 3},
        {2, 4},
        {3}
    };
    std::vector<int> infected2 = {0, 4};
    std::cout << days_until_all_infected(graph2, infected2) << std::endl; // Output: 2

    // Example3
    std::vector<std::vector<int>> graph3 = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2}
    };
    std::vector<int> infected3 = {0, 3};
    std::cout << days_until_all_infected(graph3, infected3) << std::endl; // Output: 1

    return 0;
}
