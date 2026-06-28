#include <iostream>
#include <vector>
#include <algorithm>

int road_trip(std::vector<int> times) {
  int size = times.size();
  if (size < 3) {
    return 0;
  }

  std::vector<int> dp(size);
  dp[0] = times[0];
  dp[1] = times[1];
  dp[2] = times[2];

  for (int i = 3; i < size; i++) {
    dp[i] = times[i] + std::min(dp[i-1], std::min(dp[i-2], dp[i-3]));
  }

  // Print dp array
  std::cout << "[";
  for (int i = 0; i < size; i++) {
    std::cout << dp[i];
    if (i < size - 1) std::cout << ", ";
  }
  std::cout << "]" << std::endl;

  return std::min(dp[size-1], std::min(dp[size-2], dp[size-3]));
}

int main() {
  // Example1
  int arr1[] = {8, 1, 2, 3, 9, 6, 2, 4};
  std::vector<int> times1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
  std::cout << road_trip(times1) << std::endl;

  // Example2
  int arr2[] = {8, 1, 2, 3, 9, 3, 2, 4};
  std::vector<int> times2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
  std::cout << road_trip(times2) << std::endl;

  // Example3
  int arr3[] = {10, 10};
  std::vector<int> times3(arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
  std::cout << road_trip(times3) << std::endl;

  return 0;
}
