#include <iostream>
#include <vector>
#include <numeric>

int most_weekly_days(const std::vector<int>& sales) {
  if (sales.size() < 7) {
    return 0;
  }

  int max_sales = 0;
  int l = 0, r = 7;
  while (r <= sales.size()) {
    int cur_sum = std::accumulate(sales.begin() + l, sales.begin() + r, 0);
    if (cur_sum > max_sales) {
      max_sales = cur_sum;
    }
    l++;
    r++;
  }

  return max_sales;
}

int main() {
  // Example1
  std::vector<int> sales1 = {0, 3, 7, 12, 10, 5, 0, 1, 0, 15, 12, 11, 1};
  std::cout << most_weekly_days(sales1) << std::endl;

  // Example2
  std::vector<int> sales2 = {0, 3, 7, 12};
  std::cout << most_weekly_days(sales2) << std::endl;

  return 0;
}