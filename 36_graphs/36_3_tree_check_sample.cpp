#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

void dfs(const std::vector<std::vector<int>>& graph,
         std::unordered_map<int, int>& predecessors,
         std::unordered_set<int>& visit,
         int node,
         bool& is_acyclic) {
    for (int nei : graph[node]) {
        if (visit.find(nei) == visit.end()) {
            visit.insert(nei);
            predecessors[nei] = node;
            dfs(graph, predecessors, visit, nei, is_acyclic);
        } else if (nei != predecessors[node]) {
            is_acyclic = false;
        }
    }
}

bool tree_check(const std::vector<std::vector<int>>& graph) {
    bool is_acyclic = true;
    int start = -1;

    // Find a node with only one neighbor (leaf node)
    for (int i = 0; i < graph.size(); i++) {
        if (graph[i].size() == 1) {
            start = i;
            break;
        }
    }

    if (start == -1) {
        return false;
    }

    std::unordered_map<int, int> predecessors;
    predecessors[start] = -1;
    std::unordered_set<int> visit;
    visit.insert(start);

    // DFS
    dfs(graph, predecessors, visit, start, is_acyclic);

    // Tree Check
    bool is_connected = (visit.size() == graph.size());
    if (is_connected && is_acyclic) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // Example1
    std::vector<std::vector<int>> graph1 = {
        {2},           // Node 0
        {2, 5},        // Node 1
        {0, 1, 3, 4},  // Node 2
        {2},           // Node 3
        {2},           // Node 4
        {1}            // Node 5
    };
    std::cout << (tree_check(graph1) ? "true" : "false") << std::endl;

    // Example2
    std::vector<std::vector<int>> graph2 = {
        {2},           // Node 0
        {5},           // Node 1
        {0, 3},        // Node 2
        {2},           // Node 3
        {},            // Node 4
        {1}            // Node 5
    };
    std::cout << (tree_check(graph2) ? "true" : "false") << std::endl;

    // Example3
    std::vector<std::vector<int>> graph3 = {
        {1},           // Node 0
        {0, 2, 5},     // Node 1
        {1, 3, 4},     // Node 2
        {2},           // Node 3
        {2, 5},        // Node 4
        {1, 4}         // Node 5
    };
    std::cout << (tree_check(graph3) ? "true" : "false") << std::endl;

    return 0;
}
