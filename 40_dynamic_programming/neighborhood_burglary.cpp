#include <iostream>
#include <vector>
#include <algorithm>

int neighborhood_burglary(const std::vector<int>& houses) {
  if (houses.size() == 0) {
    return 0;
  }
  if (houses.size() == 1) {
    return houses[0];
  }
  std::vector<int> dp(houses.size(), 0);
  dp[0] = houses[0];
  dp[1] = houses[1];

  for (int i=2; i<houses.size(); i++) {
    dp[i] = std::max(dp[i-2]+houses[i], dp[i-1]);
  }

  return dp[houses.size()-1];
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