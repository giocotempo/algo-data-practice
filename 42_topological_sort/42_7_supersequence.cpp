#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::unordered_map<char, std::vector<char>> construct_graph(const std::vector<std::string>& arr) {
    std::unordered_map<char, std::vector<char>> graph;

    for (const std::string& s : arr) {
        int n = static_cast<int>(s.size());
        for (int i = 0; i < n; i++) {
            if (graph.find(s[i]) == graph.end()) {
                graph[s[i]] = {};
            } 
            
            if (i < n - 1) {
                graph[s[i]].push_back(s[i+1]);
            }
        }
    }

    return graph;
}

std::vector<char> topological_sort(const std::unordered_map<char, std::vector<char>>& graph) {
    std::unordered_map<char, int> in_degrees;
    for (const auto& [node, _] : graph) {
        in_degrees[node] = 0;
    }

    for (const auto& [node, nbrs] : graph) {
        for (char nbr : nbrs) {
            in_degrees[nbr]++;
        }
    }

    std::vector<char> zero_degrees;
    for (const auto& [node, in_degree] : in_degrees) {
        if (in_degree == 0) {
            zero_degrees.push_back(node);
        }
    }

    std::vector<char> topo_order;
    while (!zero_degrees.empty()) {
        char node = zero_degrees.back();
        zero_degrees.pop_back();
        topo_order.push_back(node);

        for (char nbr : graph.at(node)) {
            in_degrees[nbr]--;
            if (in_degrees[nbr] == 0) {
                zero_degrees.push_back(nbr);
            }
        }
    }

    return topo_order;
}

bool supersequence(const std::vector<std::string>& arr) {
    std::unordered_map<char, std::vector<char>> graph = construct_graph(arr);
    std::vector<char> topo_order = topological_sort(graph);
    return topo_order.size() == graph.size();
}

int main() {
    // Example1
    std::vector<std::string> arr = {"abc", "bde", "df", "cfe"};
    std::cout << (supersequence(arr) ? "true" : "false") << std::endl;

    // Example2
    arr = {"ab", "ba"};
    std::cout << (supersequence(arr) ? "true" : "false") << std::endl;

    // Example3
    arr = {"aa"};
    std::cout << (supersequence(arr) ? "true" : "false") << std::endl;

    return 0;
}