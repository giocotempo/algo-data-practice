#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <tuple>

std::vector<std::vector<int>> multi_exit_maze(const std::vector<std::string>& maze) {
    std::vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rows = maze.size();
    int cols = maze[0].size();

    std::vector<std::vector<int>> res(rows, std::vector<int>(cols, 0));

    auto grid_bfs = [&](int i, int j) {
        std::deque<std::tuple<int, int, int>> queue;
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
        queue.push_back(std::make_tuple(i, j, 0));
        visited[i][j] = true;

        while (!queue.empty()) {
            auto [r, c, dis] = queue.front();
            queue.pop_front();

            for (const auto& dir : dirs) {
                int new_r = r + dir.first;
                int new_c = c + dir.second;

                if (new_r < 0 || new_c < 0 || new_r > rows - 1 || new_c > cols - 1) continue;
                if (visited[new_r][new_c]) continue;

                if (maze[new_r][new_c] == 'O') {
                    res[i][j] = dis + 1;
                    return;
                } else if (maze[new_r][new_c] == '.') {
                    visited[new_r][new_c] = true;
                    queue.push_back(std::make_tuple(new_r, new_c, dis + 1));
                }
            }
        }
    };

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == 'O') {
                res[i][j] = 0;
            } else if (maze[i][j] == 'X') {
                res[i][j] = -1;
            } else {
                grid_bfs(i, j);
            }
        }
    }

    return res;
}

int main() {
    // Example1
    std::vector<std::string> maze1 = {
        "...X.O",
        "OX.X..",
        "...X..",
        ".X....",
        "XOX.XX"
    };
    auto result1 = multi_exit_maze(maze1);
    for (const auto& row : result1) {
        std::cout << "[";
        for (size_t i = 0; i < row.size(); i++) {
            std::cout << row[i];
            if (i < row.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;

    // Example2
    std::vector<std::string> maze2 = {
        "...",
        ".O.",
        "..."
    };
    auto result2 = multi_exit_maze(maze2);
    for (const auto& row : result2) {
        std::cout << "[";
        for (size_t i = 0; i < row.size(); i++) {
            std::cout << row[i];
            if (i < row.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
