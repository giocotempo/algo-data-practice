#include <iostream>
#include <vector>

int search_sorted_array(std::vector<int> arr, int target) {
  if (arr.size() == 0) {
    return -1;
  }

  if (arr.size() == 1) {
    if (arr[0] == target) {
      return 0;
    } else {
      return -1;
    }
  }

  int l = 0, r = arr.size() - 1;

  while (r - l > 1) {
    int m = (l + r) / 2;
    if (arr[m] == target) {
      return m;
    }

    if (arr[m] > target) {
      r = m;
    }
    else {
      l = m;
    }
  }

  return -1;
}

int main() {
  // Example1
  std::vector<int> arr1 = {-2, 0, 3, 4, 7, 9, 11};
  int target1 = 3;
  std::cout << search_sorted_array(arr1, target1) << std::endl;

  // Example2
  std::vector<int> arr2 = {-2, 0, 3, 4, 7, 9, 11};
  int target2 = 2;
  std::cout << search_sorted_array(arr2, target2) << std::endl;
}