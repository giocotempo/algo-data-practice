#include <iostream>
#include <vector>
#include <deque>

std::vector<int> compress_array(const std::vector<int>& arr) {
  std::deque<int> stack;

  std::function<void(int)> add_stack = [&](int num) {
    if (stack.empty()) {
      stack.push_back(num);
    } else if (stack.back() == num) {
      stack.pop_back();
      add_stack(2 * num);
    } else {
      stack.push_back(num);
    }
  };

  for (int num : arr) {
    add_stack(num);
  }

  return std::vector<int>(stack.begin(), stack.end());
}

void print_vector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    // Example1
    std::vector<int> arr1 = {8, 4, 2, 2, 2, 4};
    print_vector(compress_array(arr1));

    // Example2
    std::vector<int> arr2 = {4, 4, 4, 4};
    print_vector(compress_array(arr2));

    // Example3
    std::vector<int> arr3 = {1, 2, 3, 4};
    print_vector(compress_array(arr3));

    return 0;
}
