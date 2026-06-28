#include <iostream>
#include <vector>
#include <climits>
#include <numeric>

int shortest_period_with_over_20_sales(std::vector<int> sales) {
  int l = 0, r = 0;
  int cur_min = INT_MAX;

  while (r < sales.size()) {
    int window = std::accumulate(sales.begin() + l, sales.begin() + r + 1, 0);
    if (window > 20 && r - l + 1 < cur_min) {
      cur_min = r - l + 1;
      l += 1;
    } else {
      r += 1;
    }
  }

  return cur_min != INT_MAX ? cur_min : -1;
}

int main() {
  // Example1
  std::vector<int> sales1 = {5, 10, 15, 5, 10};
  std::cout << shortest_period_with_over_20_sales(sales1) << std::endl;

  // Example2
  std::vector<int> sales2 = {5, 10, 4, 5, 10};
  std::cout << shortest_period_with_over_20_sales(sales2) << std::endl;

  // Example3
  std::vector<int> sales3 = {5, 5, 5, 5};
  std::cout << shortest_period_with_over_20_sales(sales3) << std::endl;

  return 0;
}
