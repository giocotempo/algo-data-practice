#include <iostream>
#include <vector>
#include <queue>
#include <map>

std::vector<std::vector<int> > shortest_path_queries(std::vector<std::vector<int> >& graph, int start, std::vector<int>& queries) {
    std::vector<std::vector<int> > output;
    std::queue<std::pair<int, int> > q;
    q.push(std::make_pair(-1, start)); // -1 represents None/null for previous node
    std::map<int, std::vector<int> > shortest_paths;

    while (!q.empty()) {
        int prev = q.front().first;
        int node = q.front().second;
        q.pop();

        if (prev == -1) {
            std::vector<int> start_path;
            start_path.push_back(start);
            shortest_paths[node] = start_path;
            for (int nei : graph[node]) {
                q.push(std::make_pair(node, nei));
            }
        } else {
            if (shortest_paths.find(node) == shortest_paths.end()) {
                std::vector<int> shortest_path = shortest_paths[prev];
                shortest_path.push_back(node);
                shortest_paths[node] = shortest_path;
                for (int nei : graph[node]) {
                    q.push(std::make_pair(node, nei));
                }
            }
        }
    }

    for (int query : queries) {
        if (shortest_paths.find(query) == shortest_paths.end()) {
            output.push_back(std::vector<int>());
        } else {
            output.push_back(shortest_paths[query]);
        }
    }

    return output;
}

void print_result(std::vector<std::vector<int> >& result) {
    std::cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            std::cout << result[i][j];
            if (j < result[i].size() - 1) std::cout << ", ";
        }
        std::cout << "]";
        if (i < result.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    // Example1
    std::vector<std::vector<int> > graph1;
    graph1.push_back(std::vector<int>(1, 1));           // Node 0: {1}
    std::vector<int> node1; node1.push_back(0); node1.push_back(2); node1.push_back(5); node1.push_back(4);
    graph1.push_back(node1);  // Node 1
    std::vector<int> node2; node2.push_back(1); node2.push_back(4); node2.push_back(5);
    graph1.push_back(node2);  // Node 2
    graph1.push_back(std::vector<int>());               // Node 3: {}
    std::vector<int> node4; node4.push_back(5); node4.push_back(2); node4.push_back(1);
    graph1.push_back(node4);  // Node 4
    std::vector<int> node5; node5.push_back(1); node5.push_back(2); node5.push_back(4);
    graph1.push_back(node5);  // Node 5

    int start1 = 0;
    std::vector<int> queries1;
    queries1.push_back(1); queries1.push_back(0); queries1.push_back(3); queries1.push_back(4);
    std::vector<std::vector<int> > result1 = shortest_path_queries(graph1, start1, queries1);
    print_result(result1);

    // Example2
    std::vector<std::vector<int> > graph2;
    graph2.push_back(std::vector<int>(1, 1));           // Node 0: {1}
    std::vector<int> node2_1; node2_1.push_back(0); node2_1.push_back(2);
    graph2.push_back(node2_1);  // Node 1
    graph2.push_back(std::vector<int>(1, 1));           // Node 2: {1}

    int start2 = 0;
    std::vector<int> queries2;
    queries2.push_back(1); queries2.push_back(2);
    std::vector<std::vector<int> > result2 = shortest_path_queries(graph2, start2, queries2);
    print_result(result2);

    // Example3
    std::vector<std::vector<int> > graph3;
    graph3.push_back(std::vector<int>(1, 1));           // Node 0: {1}
    graph3.push_back(std::vector<int>(1, 0));           // Node 1: {0}
    graph3.push_back(std::vector<int>(1, 3));           // Node 2: {3}
    graph3.push_back(std::vector<int>(1, 2));           // Node 3: {2}

    int start3 = 0;
    std::vector<int> queries3;
    queries3.push_back(1); queries3.push_back(2); queries3.push_back(3);
    std::vector<std::vector<int> > result3 = shortest_path_queries(graph3, start3, queries3);
    print_result(result3);

    return 0;
}
