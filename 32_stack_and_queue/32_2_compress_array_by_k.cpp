#include <deque>
#include <vector>
#include <iostream>

bool can_compress(std::deque<int>& stack, int k, int num);
void compress(std::deque<int>& stack, int k);

std::vector<int> compress_array_by_k(const std::vector<int>& arr, int k) {
  std::deque<int> stack;

  for (int num : arr) {
    stack.push_back(num);
    if (can_compress(stack, k, num)) {
      compress(stack, k);
    }
  }

  return std::vector<int>(stack.begin(), stack.end());
}

bool can_compress(std::deque<int>& stack, int k, int num) {
  if (static_cast<int>(stack.size()) < k) {
    return false;
  }

  std::deque<int> tmp;
  auto restore = [&]() {
    while (!tmp.empty()) {
      stack.push_back(tmp.back());
      tmp.pop_back();
    }
  };

  for (int i = 0; i < k; ++i) {
    int val = stack.back();
    stack.pop_back();
    tmp.push_back(val);
    if (val != num) {
      restore();
      return false;
    }
  }
  restore();
  return true;
}

void compress(std::deque<int>& stack, int k) {
  int compressed_val = 0;
  for (int i = 0; i < k; ++i) {
    compressed_val += stack.back();
    stack.pop_back();
  }
  stack.push_back(compressed_val);
  if (can_compress(stack, k, compressed_val)) {
    compress(stack, k);
  }
}

int main() {
    // Example1
    std::vector<int> arr1 = {1, 9, 9, 3, 3, 3, 4};
    int k1 = 3;
    std::vector<int> result1 = compress_array_by_k(arr1, k1);
    std::cout << "[";
    for (size_t i = 0; i < result1.size(); ++i) {
        std::cout << result1[i];
        if (i < result1.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    // Example2
    std::vector<int> arr2 = {8, 4, 2, 2};
    int k2 = 2;
    std::vector<int> result2 = compress_array_by_k(arr2, k2);
    std::cout << "[";
    for (size_t i = 0; i < result2.size(); ++i) {
        std::cout << result2[i];
        if (i < result2.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    // Example3
    std::vector<int> arr3 = {4, 4, 4, 4};
    int k3 = 5;
    std::vector<int> result3 = compress_array_by_k(arr3, k3);
    std::cout << "[";
    for (size_t i = 0; i < result3.size(); ++i) {
        std::cout << result3[i];
        if (i < result3.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
