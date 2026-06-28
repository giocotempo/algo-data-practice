#include <iostream>
#include <vector>
#include <algorithm>

int neighborhood_burglary(std::vector<int> houses) {
  std::vector<int> dp(houses.size(), 0);
  dp[0] = houses[0];
  dp[1] = std::max(houses[0], houses[1]);

  for (int i = 2; i < houses.size(); i++) {
    dp[i] = std::max(dp[i-1], dp[i-2] + houses[i]);
  }

  return dp.back();
}

int main() {
  std::vector<int> houses;
  houses.push_back(200);
  houses.push_back(300);
  houses.push_back(200);
  houses.push_back(50);
  std::cout << neighborhood_burglary(houses) << std::endl;
  return 0;
}
