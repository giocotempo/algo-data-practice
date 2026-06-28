#include <iostream>
#include <vector>

std::vector<int> parity_sorting(std::vector<int>& arr) {
  int l = 0, r = arr.size()-1;
  while (l < r) {
    if (arr[l] % 2 == 1 && arr[r] % 2 == 0) {
      std::swap(arr[l], arr[r]);
      l += 1;
      r -= 1;
    } else if (arr[l] % 2 == 0 && arr[r] % 2 == 1) {
      l += 1;
      r -= 1;
    } else if (arr[l] % 2 == 0 && arr[r] % 2 == 0) {
      l += 1;
    } else {
      r -= 1;
    }
  }

  return arr;
}

int main() {
  // Example1
  std::vector<int> arr = {1, 2, 3, 4, 5};
  std::vector<int> result = parity_sorting(arr);
  std::cout << "[";
  for (size_t i = 0; i < result.size(); i++) {
    std::cout << result[i];
    if (i < result.size() - 1) std::cout << ", ";
  }
  std::cout << "]" << std::endl;

  // Example2
  arr = {5, 1, 3, 1, 5};
  result = parity_sorting(arr);
  std::cout << "[";
  for (size_t i = 0; i < result.size(); i++) {
    std::cout << result[i];
    if (i < result.size() - 1) std::cout << ", ";
  }
  std::cout << "]" << std::endl;

  // Example3
  arr = {1, 4, 5, 2, 6, 8, 7, 10};
  result = parity_sorting(arr);
  std::cout << "[";
  for (size_t i = 0; i < result.size(); i++) {
    std::cout << result[i];
    if (i < result.size() - 1) std::cout << ", ";
  }
  std::cout << "]" << std::endl;

  return 0;
}
