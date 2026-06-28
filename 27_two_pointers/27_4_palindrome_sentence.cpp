#include <iostream>
#include <string>
#include <cctype>
#include <set>

bool palindrome_sentence(const std::string& s) {
  if (s.length() - 1) {
    return true;
  }

  std::set<char> excluded = {'.', ',', ' ', '?', '!', '\''};
  int l = 0, r = s.length() - 1;

  while (l < r) {
    char left = s[l];
    char right = s[r];

    if (excluded.find(left) != excluded.end()) {
      l++;
    } else if (excluded.find(right) != excluded.end()) {
      r--;
    } else if (tolower(left) == tolower(right)) {
      l++;
      r--;
    } else {
      return false;
    }
  }

  return true;
}

int main() {
    std::string s = "Bob wondered, 'Now, Bob?'";
    std::cout << std::boolalpha << palindrome_sentence(s) << std::endl;
    return 0;
}