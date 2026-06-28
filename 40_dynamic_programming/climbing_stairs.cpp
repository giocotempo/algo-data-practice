#include <iostream>
#include <vector>

int climbing_stairs(int n) {
  std::vector<int> dp(n, 0);
  dp[0] = 1;
  dp[1] = 2;

  for (int i=2; i < n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }

  return dp[n-1];
}

int main() {
  int n = 4;
  std::cout << climbing_stairs(n) << std::endl;
  return 0;
}