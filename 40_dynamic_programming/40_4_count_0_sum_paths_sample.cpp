#include <iostream>
#include <vector>

int count_0_sum_paths(std::vector<std::vector<int> >& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    std::vector<std::vector<int> > dp(rows, std::vector<int>(cols, 0));

    // Initialize first column
    for (int i = 0; i < rows; i++) {
        if (grid[i][0] == 0) {
            dp[i][0] = 1;
        } else {
            dp[i][0] = 0;
            // Break to set remaining cells to 0
            break;
        }
    }

    // Initialize first row
    for (int j = 0; j < cols; j++) {
        if (grid[0][j] == 0) {
            dp[0][j] = 1;
        } else {
            dp[0][j] = 0;
            // Break to set remaining cells to 0
            break;
        }
    }

    // Fill the dp table
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i][j-1];
        }
    }

    return dp[rows-1][cols-1];
}

int main() {
    // Example 1
    std::vector<std::vector<int> > grid1;
    grid1.push_back(std::vector<int>());
    grid1[0].push_back(0); grid1[0].push_back(1); grid1[0].push_back(1);
    grid1.push_back(std::vector<int>());
    grid1[1].push_back(0); grid1[1].push_back(0); grid1[1].push_back(0);
    grid1.push_back(std::vector<int>());
    grid1[2].push_back(1); grid1[2].push_back(0); grid1[2].push_back(0);
    std::cout << count_0_sum_paths(grid1) << std::endl;

    // Example 2
    std::vector<std::vector<int> > grid2;
    grid2.push_back(std::vector<int>());
    grid2[0].push_back(1);
    std::cout << count_0_sum_paths(grid2) << std::endl;

    return 0;
}
