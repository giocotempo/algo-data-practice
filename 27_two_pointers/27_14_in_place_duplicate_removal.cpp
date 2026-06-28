#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>

int in_place_duplicate_removal(std::vector<int>& arr) {
  int writer = 0, seeker = 0;
  int cur_max = std::numeric_limits<int>::lowest();

  while (seeker < static_cast<int>(arr.size())) {
    if (arr[writer] > cur_max) {
      cur_max = arr[writer];
      writer++;
      seeker++;
    } else if (arr[seeker] > cur_max) {
      std::swap(arr[writer], arr[seeker]);
      cur_max = arr[writer];
      writer++;
      seeker++;
    } else {
      seeker++;
    }
  }
  return writer;
}

int main() {
    // Example1
    std::vector<int> arr1 = {1, 2, 2, 3, 3, 3, 5};
    std::cout << in_place_duplicate_removal(arr1) << std::endl;

    // Example2
    std::vector<int> arr2 = {1, 3, 4, 4, 2, 5, 6, 6, 6, 8, 9, 10};
    std::cout << in_place_duplicate_removal(arr2) << std::endl;

    return 0;
}
