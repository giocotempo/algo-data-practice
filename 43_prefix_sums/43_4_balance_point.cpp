#include <iostream>
#include <vector>

int balance_point(const std::vector<int>& arr) {
  std::vector<int> prefix_sum;

  for (size_t i = 0; i < arr.size(); i++) {
    if (i == 0) {
      prefix_sum.push_back(arr[0]);
    } else {
      prefix_sum.push_back(prefix_sum[i-1] + arr[i]);
    }
  }

  for (size_t i = 1; i < arr.size() - 1; i++) {
    if (prefix_sum[i-1] == (prefix_sum.back() - prefix_sum[i])) {
      return i;
    }
  }
  return -1;
}

int main() {
    std::vector<int> arr = {3, 5, -2, 7, 2, 2, 2};
    std::cout << balance_point(arr) << std::endl;
    return 0;
}