#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> split(const std::string& s, char c) {
  std::vector<std::string> output;
  std::string acc = "";

  for (char el : s) {
    if (el == c) {
      output.push_back(acc);
      acc = "";
    } else {
      acc += el;
    }
  }

  output.push_back(acc);

  return output;
}

int main() {
  std::string s1 = "split by space";
  char c1 = ' ';
  std::vector<std::string> result1 = split(s1, c1);
  std::cout << "[";
  for (size_t i = 0; i < result1.size(); i++) {
    std::cout << "\"" << result1[i] << "\"";
    if (i < result1.size() - 1) std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}