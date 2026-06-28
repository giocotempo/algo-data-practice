#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

bool multi_account_cheating(const std::vector<std::pair<std::string, std::vector<std::string>>>& users) {
  std::unordered_set<std::string> hashset;
  for (const auto& user: users) {
    const std::vector<std::string>& ips = user.second;
    for (const std::string& ip : ips) {
      if (hashset.find(ip) == hashset.end()) {
        hashset.insert(ip);
      } else {
        return true;
      }
    }
  }
  return false;
}

int main() {
  // Example
  std::vector<std::pair<std::string, std::vector<std::string>>> users = {
    {"mike", {"203.0.3.10", "208.51.0.5", "52.0.2.5"}},
    {"bob", {"111.0.0.10", "222.0.0.5", "222.0.0.8"}},
    {"bob2", {"222.0.0.5", "222.0.0.8", "111.0.0.10"}}
  };
  std::cout << (multi_account_cheating(users) ? "true" : "false") << std::endl;
  return 0;
}
