#include <iostream>
#include <vector>

int count_subarrays_with_sum_k(const std::vector<int>& arr, int k) {
    std::vector<int> prefix_sum = {arr[0]};
    for (std::size_t i = 1; i < arr.size(); i++) {
        prefix_sum.push_back(prefix_sum[i-1] + arr[i]);
    }

    int count = 0;
    for (std::size_t i = 0; i < arr.size(); i++) {
        if (prefix_sum[i] == k) {
            count++;
        }
        for (std::size_t j = 0; j < i; j++) {
            if (prefix_sum[i] - prefix_sum[j] == k) {
                count++;
            }
        }
    }

    return count;
}

int main() {
  // Example1
  std::vector<int> arr1 = {1, 2, 3, 2, 1};
  int k1 = 3;
  std::cout << count_subarrays_with_sum_k(arr1, k1) << std::endl;

  // Example2
  std::vector<int> arr2 = {-1, -2, -3, 2, 1};
  int k2 = -3;
  std::cout << count_subarrays_with_sum_k(arr2, k2) << std::endl;

  return 0;
}
