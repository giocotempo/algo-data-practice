#include <iostream>
#include <vector>
#include <string>

std::string join(std::vector<std::string> arr, std::string s) {
  if (arr.size() == 0) {
    return "";
  }

  if (arr.size() == 1) {
    return arr[0];
  }

  std::string result = "";

  for (int i = 0; i < arr.size(); i++) {
    result += arr[i];
    if (i < arr.size() - 1) {
      result += s;
    }
  }

  return result;
}

int main() {
  // Example1
  std::vector<std::string> arr1 = {"join", "by", "space"};
  std::string s1 = " ";
  std::cout << join(arr1, s1) << std::endl;

  // Example2
  std::vector<std::string> arr2 = {"b", "", "k", "", "p", "r n", "", "d", "d!!"};
  std::string s2 = "ee";
  std::cout << join(arr2, s2) << std::endl;

}