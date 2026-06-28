#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> array_reversal(std::vector<std::string>& arr) {
  int l = 0;
  int r = arr.size() - 1;

  while (l < r) {
    std::string temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
    l++;
    r--;
  }

  return arr;
}

int main() {
    std::vector<std::string> arr1 = {"a", "b", "c", "d", "f", "g", "h"};
    array_reversal(arr1);
    std::cout << "[";
    for (size_t i = 0; i < arr1.size(); i++) {
        std::cout << "'" << arr1[i] << "'";
        if (i < arr1.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    std::vector<std::string> arr2 = {"b", "c", "t", "c", "i"};
    array_reversal(arr2);
    std::cout << "[";
    for (size_t i = 0; i < arr2.size(); i++) {
        std::cout << "'" << arr2[i] << "'";
        if (i < arr2.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
