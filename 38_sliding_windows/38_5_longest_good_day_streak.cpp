#include <iostream>
#include <vector>
#include <algorithm>

int longest_good_day_streak(std::vector<int> sales) {
  int l = 0, r = 0;
  int longest_days = 0;
  while (r < sales.size()) {
    if (sales[r] >= 10) {
      if (r - l + 1 > longest_days) {
        longest_days = r - l + 1;
      }
      r++;
    } else {
      r++;
      l = r;
    }
  }

  return longest_days;
}

int main() {
  // Example1
  std::vector<int> sales1 = {0, 14, 7, 12, 10, 20};
  std::cout << longest_good_day_streak(sales1) << std::endl;

  // Example2
  std::vector<int> sales2 = {0, 14, 7, 12, 10, 20, 23, 2};
  std::cout << longest_good_day_streak(sales2) << std::endl;

  return 0;
}
