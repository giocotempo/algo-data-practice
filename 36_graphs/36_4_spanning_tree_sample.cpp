#include <vector>
#include <unordered_set>
#include <iostream>
#include <functional>

std::vector<std::vector<int>> spanning_tree(const std::vector<std::vector<int>>& graph) {
    if (graph.size() <= 1) {
        return {};
    }

    std::vector<std::vector<int>> output;
    std::unordered_set<int> visit;
    visit.insert(0);

    std::function<void(int)> dfs = [&](int node) {
        for (int nei : graph[node]) {
            if (visit.find(nei) == visit.end()) {
                output.push_back({node, nei});
                visit.insert(nei);
                dfs(nei);
            }
        }
    };

    dfs(0);

    return output;
}

int main() {
    std::vector<std::vector<int>> graph = {
        {1},           // Node 0
        {0, 2, 5},     // Node 1
        {1, 3, 4},     // Node 2
        {2},           // Node 3
        {2, 5},        // Node 4
        {1, 4}         // Node 5
    };

    std::vector<std::vector<int>> result = spanning_tree(graph);

    std::cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << "[" << result[i][0] << ", " << result[i][1] << "]";
        if (i < result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
