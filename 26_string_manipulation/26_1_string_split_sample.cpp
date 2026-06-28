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
  // Example1
  std::string s1 = "split by space";
  char c1 = ' ';
  std::vector<std::string> result1 = split(s1, c1);
  std::cout << "[";
  for (size_t i = 0; i < result1.size(); i++) {
    std::cout << "\"" << result1[i] << "\"";
    if (i < result1.size() - 1) std::cout << ", ";
  }
  std::cout << "]" << std::endl;

  // Example2
  std::string s2 = "beekeeper needed";
  char c2 = 'e';
  std::vector<std::string> result2 = split(s2, c2);
  std::cout << "[";
  for (size_t i = 0; i < result2.size(); i++) {
    std::cout << "\"" << result2[i] << "\"";
    if (i < result2.size() - 1) std::cout << ", ";
  }
  std::cout << "]" << std::endl;

  // Example3
  std::string s3 = "/home/./..//Documents/";
  char c3 = '/';
  std::vector<std::string> result3 = split(s3, c3);
  std::cout << "[";
  for (size_t i = 0; i < result3.size(); i++) {
    std::cout << "\"" << result3[i] << "\"";
    if (i < result3.size() - 1) std::cout << ", ";
  }
  std::cout << "]" << std::endl;

  return 0;
}
