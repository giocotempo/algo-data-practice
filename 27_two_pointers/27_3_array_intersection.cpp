#include <iostream>
#include <vector>

std::vector<int> array_intersection(std::vector<int>& arr1, std::vector<int>& arr2) {
  std::vector<int> output;
  int p1 = 0, p2 = 0;

  while (p1 < arr1.size() && p2 < arr2.size()) {
    if (arr1[p1] == arr2[p2]) {
      output.push_back(arr1[p1]);
      p1++;
      p2++;
    } else if (arr1[p1] < arr2[p2]) {
      p1++;
    } else if (arr1[p1] > arr2[p2]) {
      p2++;
    }
  }

  return output;
}

int main() {
  std::vector<int> arr1;
  arr1.push_back(1);
  arr1.push_back(2);
  arr1.push_back(3);

  std::vector<int> arr2;
  arr2.push_back(1);
  arr2.push_back(3);
  arr2.push_back(5);

  std::vector<int> result1 = array_intersection(arr1, arr2);

  for (size_t i = 0; i < result1.size(); i++) {
    std::cout << result1[i] << " ";
  }
  std::cout << std::endl;

  arr1.clear();
  arr1.push_back(1);
  arr1.push_back(1);
  arr1.push_back(1);

  arr2.clear();
  arr2.push_back(1);
  arr2.push_back(1);

  std::vector<int> result2 = array_intersection(arr1, arr2);

  for (size_t i = 0; i < result2.size(); i++) {
    std::cout << result2[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
