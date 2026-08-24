#include <iostream>
#include <set>
#include <utility>
#include <vector>

int count_islands(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    int result = 0;
    std::set<std::pair<int, int>> visited;

    auto dfs = [&](auto&& self, int i, int j) -> void {
        std::vector<std::pair<int, int>> dirs = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1},
        };

        if (visited.find({i, j}) != visited.end()) {
            return;
        }

        if (i < 0 || i >= static_cast<int>(matrix.size()) ||
            j < 0 || j >= static_cast<int>(matrix[0].size())) {
            return;
        }

        visited.insert({i, j});
        if (matrix[i][j] == 1) {
            for (const auto& dir : dirs) {
                self(self, i + dir.first, j + dir.second);
            }
        }
    };

    for (int i = 0; i < static_cast<int>(matrix.size()); i++) {
        for (int j = 0; j < static_cast<int>(matrix[0].size()); j++) {
            if (matrix[i][j] == 1 && visited.find({i, j}) == visited.end()) {
                result++;
            }
            dfs(dfs, i, j);
        }
    }

    return result;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1},
    };

    std::cout << count_islands(matrix) << std::endl;
    return 0;
}
