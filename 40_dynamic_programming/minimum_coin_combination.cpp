#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

void count_minimum_combination(int t, std::map<int, int>& dp) {
  if (dp.find(t) != dp.end()) {
    return;
  }

  int min_numbers = -1;
  dp[t] = min_numbers;

  for (int i = 1; i < t; i++) {
    count_minimum_combination(i, dp);
    count_minimum_combination(t-1, dp);
    if (dp[i] != -1 && dp[t-i] != -1) {
      if (dp[t] == -1) {
        dp[t] = dp[i] + dp[t-i];
      } else {
        dp[t] = std::min(dp[t], dp[i] + dp[t-i]);
      }
    }
  }
}

int minimum_coin_combination(std::vector<int> coins, int target) {
  std::map<int, int> dp;
  dp[0] = -1;
  for (int coin : coins) {
    dp[coin] = 1;
  }

  count_minimum_combination(target, dp);
  return dp[target];
}

int main() {
    // Example1
    std::vector<int> coins1 = {1, 2, 3};
    int target1 = 5;
    std::cout << minimum_coin_combination(coins1, target1) << std::endl;

    // Example2
    std::vector<int> coins2 = {2, 4};
    int target2 = 5;
    std::cout << minimum_coin_combination(coins2, target2) << std::endl;

    return 0;
}
