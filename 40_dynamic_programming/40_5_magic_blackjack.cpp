#include <iostream>
#include <vector>
#include <numeric>

int magic_blackjack() {
  // Rule1
  int min_safe_value = 16;
  int max_safe_value = 21;
  // Rule2
  int max_deck_value = 10;
  // Initialization
  std::vector<int> dp(min_safe_value + max_deck_value, 0);
  dp[0] = 0;
  dp[1] = 1;

  for (int i = 2; i < min_safe_value + max_deck_value; i++) {
    if (i <= 10) {
      int sum = std::accumulate(dp.begin(), dp.end(), 0);
      dp[i] = sum + 1;
    }
    if (i == 11) {
      int sum = std::accumulate(dp.begin(), dp.end(), 0);
      dp[i] = sum;
    }
    if (i >= 12) {
      int start_idx = i - max_deck_value;
      int end_idx = min_safe_value;
      int sum = std::accumulate(dp.begin() + start_idx, dp.begin() + end_idx, 0);
      dp[i] = sum;
    }
  }

  int result = std::accumulate(dp.begin() + max_safe_value + 1, dp.end(), 0);
  return result;
}

int main() {
    std::cout << magic_blackjack() << std::endl;
    return 0;
}