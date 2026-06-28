#include <iostream>
#include <vector>
#include <numeric>

int most_sales_in_k_days(const std::vector<int>& sales, int k) {
  int l = 0, r = 0;
  int max_sales_index = -1;
  int max_sales = 0;
  while (r <= sales.size()) {
    r++;
    if (r - l == k) {
      int current_sum = accumulate(sales.begin() + 1, sales.begin() + r, 0);
      if (current_sum > max_sales) {
        max_sales = current_sum;
        max_sales_index = l;
      }
      l++;
    }
  }
  return max_sales_index;
}

int main() {
  std::vector<int> sales = {8, 1, 3, 7};
  int k = 2;
  std::cout << most_sales_in_k_days(sales, k) << std::endl;
  return 0;
}