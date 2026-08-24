#include <iostream>
#include <set>
#include <utility>
#include <vector>

bool within_matrix(int i, int j, const std::vector<std::vector<int>>& matrix) {
    return 0 <= i && i < static_cast<int>(matrix.size()) &&
           0 <= j && j < static_cast<int>(matrix[0].size());
}

int matrix_infection(std::vector<std::vector<int>>& matrix) {
    std::set<std::pair<int, int>> visited;
    int seconds_to_infected = 0;
    const std::vector<std::pair<int, int>> dirs = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    auto dfs = [&](auto&& self, int i, int j, int seconds) -> void {
        std::pair<int, int> cell = {i, j};
        if (visited.find(cell) != visited.end()) {
            return;
        }
        visited.insert(cell);

        if (matrix[i][j] == 0) {
            return;
        }

        if (matrix[i][j] == 1) {
            matrix[i][j] = 2;
            seconds += 1;
            if (seconds > seconds_to_infected) {
                seconds_to_infected = seconds;
            }
        }

        for (const auto& dir : dirs) {
            int new_i = i + dir.first;
            int new_j = j + dir.second;
            if (within_matrix(new_i, new_j, matrix)) {
                self(self, new_i, new_j, seconds);
            }
        }
    };

    for (int i = 0; i < static_cast<int>(matrix.size()); i++) {
        for (int j = 0; j < static_cast<int>(matrix[0].size()); j++) {
            if (matrix[i][j] == 2 && visited.find({i, j}) == visited.end()) {
                dfs(dfs, i, j, 0);
            }
        }
    }

    for (int i = 0; i < static_cast<int>(matrix.size()); i++) {
        for (int j = 0; j < static_cast<int>(matrix[0].size()); j++) {
            if (matrix[i][j] == 1) {
                return -1;
            }
        }
    }

    return seconds_to_infected;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 1, 1, 0},
        {0, 0, 2, 1},
        {0, 1, 1, 0}
    };

    std::cout << matrix_infection(matrix) << std::endl;
    return 0;
}
