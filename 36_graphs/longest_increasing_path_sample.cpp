#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int longest_increasing_path(const std::vector<std::vector<int>>& graph) {
    if (graph.empty() || graph[0].empty()) {
        return 0;
    }

    const int rows = static_cast<int>(graph.size());
    const int columns = static_cast<int>(graph[0].size());
    const std::vector<std::pair<int, int>> directions = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
    };
    std::vector<std::vector<int>> longest_paths(
        rows, std::vector<int>(columns, 0));

    auto dfs = [&](auto&& self, int row, int column) -> int {
        if (longest_paths[row][column] != 0) {
            return longest_paths[row][column];
        }

        int longest_path = 1;

        for (const auto& direction : directions) {
            const int new_row = row + direction.first;
            const int new_column = column + direction.second;

            const bool is_within_graph =
                0 <= new_row && new_row < rows &&
                0 <= new_column && new_column < columns;

            if (is_within_graph &&
                graph[new_row][new_column] > graph[row][column]) {
                longest_path = std::max(
                    longest_path, 1 + self(self, new_row, new_column));
            }
        }

        longest_paths[row][column] = longest_path;
        return longest_path;
    };

    int result = 0;

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            result = std::max(result, dfs(dfs, row, column));
        }
    }

    return result;
}

int main() {
    const std::vector<std::vector<int>> graph = {
        {1, 5, 8},
        {3, 4, 4},
        {7, 9, 2},
    };

    std::cout << longest_increasing_path(graph) << std::endl;
    return 0;
}
