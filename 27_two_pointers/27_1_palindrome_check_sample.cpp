#include <iostream>
#include <string>

bool is_palindrome(const std::string& s) {
  if (s.length() == 0) {
    return false;
  }

  int l = 0, r = s.length() - 1;
  while (l < r) {
    if (s[l] != s[r]) {
      return false;
    }
    l++;
    r--;
  }

  return true;
}

int main() {
  // Example1
  std::string s = "level";
  std::cout << std::boolalpha << is_palindrome(s) << std::endl;

  // Example2
  s = "naan";
  std::cout << std::boolalpha << is_palindrome(s) << std::endl;

  // Example3
  s = "palindrome";
  std::cout << std::boolalpha << is_palindrome(s) << std::endl;

  return 0;
}
