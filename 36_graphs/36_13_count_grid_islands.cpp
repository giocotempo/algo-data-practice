#include <iostream>
#include <vector>
#include <set>
#include <utility>

int count_grid_islands(const std::vector<std::vector<int>>& grid) {
  if (grid.empty() || grid[0].empty()) {
    return 0;
  }

  std::set<std::pair<int, int>> visited;
  std::vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int count = 0;
  int rows = grid.size();
  int cols = grid[0].size();

  auto grid_dfs = [&](auto&& self, int r, int c) -> void {
    for (const auto& dir : dirs) {
      int new_r = r + dir.first;
      int new_c = c + dir.second;

      if (new_r < 0 || new_c < 0 || new_r > rows - 1 || new_c > cols - 1) {
        continue;
      }

      std::pair<int, int> pos = {new_r, new_c};
      if (visited.find(pos) == visited.end()) {
        visited.insert(pos);
        if (grid[new_r][new_c] == 1) {
          self(self, new_r, new_c);
        }
      }
    }
  };

  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      std::pair<int, int> pos = {r, c};
      if (visited.find(pos) != visited.end()) {
        continue;
      }
      if (grid[r][c] == 0) {
        visited.insert(pos);
      } else {
        visited.insert(pos);
        count++;
        grid_dfs(grid_dfs, r, c);
      }
    }
  }

  return count;
}

int main() {
    // Example 1
    std::vector<std::vector<int>> grid1 = {
        {0, 0, 1, 0},
        {1, 1, 0, 1},
        {0, 0, 1, 1}
    };
    std::cout << count_grid_islands(grid1) << std::endl;

    // Example 2
    std::vector<std::vector<int>> grid2 = {{}};
    std::cout << count_grid_islands(grid2) << std::endl;

    return 0;
}
