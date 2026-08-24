#include <algorithm>
#include <iostream>
#include <vector>

int knapsack(int cap, const std::vector<int>& weights, const std::vector<int>& values) {
    int n = static_cast<int>(weights.size());
    std::vector<std::vector<int>> dp(n, std::vector<int>(cap + 1, 0));

    for (int c = weights[0]; c <= cap; c++) {
        dp[0][c] = values[0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= cap; j++) {
            if (j >= weights[i]) {
                dp[i][j] = std::max(dp[i-1][j-weights[i]]+values[i], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n-1][cap];
}

int main() {
    int cap = 7;
    std::vector<int> weights = {5, 3, 4, 1};
    std::vector<int> values = {70, 50, 40, 10};

    std::cout << knapsack(cap, weights, values) << std::endl;

    return 0;
}