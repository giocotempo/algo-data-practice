#include <iostream>
#include <vector>
#include <algorithm>

int restaurant_ratings(std::vector<int>& ratings) {
  int n = ratings.size();
  std::vector<int> dp(n, 0);
  dp[0] = ratings[0];
  dp[1] = std::max(dp[0], ratings[1]);

  for (int i=2; i<n; i++) {
    dp[i] = std::max(dp[i-1], ratings[i]+dp[i-2]);
  }

  return dp[n-1];
}

int main() {
    // Example1
    std::vector<int> ratings1 = {8, 1, 3, 9, 5, 2, 1};
    std::cout << restaurant_ratings(ratings1) << std::endl;

    // Example2
    std::vector<int> ratings2 = {8, 1, 3, 7, 5, 2, 4};
    std::cout << restaurant_ratings(ratings2) << std::endl;

    return 0;
}

