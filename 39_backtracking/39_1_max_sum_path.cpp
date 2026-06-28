#include <iostream>
#include <vector>
#include <algorithm>

void dfs(const std::vector<std::vector<int>>& grid, int i, int j, int sum_path, int& max_sum_path) {
  int h = grid.size();
  int w = grid[0].size();
  sum_path += grid[i][j];

  if (i == h-1 && j == w-1) {
    max_sum_path = std::max(max_sum_path, sum_path);
  }
  else {
    if (i < h - 1) {
      dfs(grid, i+1, j, sum_path, max_sum_path);
    }
    if (j < w - 1) {
      dfs(grid, i, j+1, sum_path, max_sum_path);
    }
  }
}

int calc_max_sum_path(const std::vector<std::vector<int>>& grid) {
  int max_sum_path = 0;
  dfs(grid, 0, 0, 0, max_sum_path);
  return max_sum_path;
}

int main() {
    // Example1
    std::vector<std::vector<int> > grid;
    grid.push_back(std::vector<int>());
    grid[0].push_back(1); grid[0].push_back(4); grid[0].push_back(3);
    grid.push_back(std::vector<int>());
    grid[1].push_back(2); grid[1].push_back(7); grid[1].push_back(6);
    grid.push_back(std::vector<int>());
    grid[2].push_back(5); grid[2].push_back(8); grid[2].push_back(9);
    std::cout << calc_max_sum_path(grid) << std::endl;

    // Example2
    std::vector<std::vector<int> > grid2;
    grid2.push_back(std::vector<int>());
    grid2[0].push_back(5);
    std::cout << calc_max_sum_path(grid2) << std::endl;

    return 0;
}