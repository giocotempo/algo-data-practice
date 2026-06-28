#include <iostream>
#include <string>

int index_of(const std::string& s, const std::string& t) {
  int i = 0;
  while (i < s.length() - t.length()) {
    if (s.substr(i, t.length()) == t) {
      return i;
    } else {
      i++;
    }
  }

  return -1;
}

int main() {
  std::string s = "jjagjfahudgnk";
  std::string t = "fah";
  std::cout << index_of(s, t) << std::endl;

  return 0;
}
