#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::string most_shared_account(const std::vector<std::pair<std::string, std::string>>& connections) {
  std::unordered_map<std::string, int> hashmap;
  int max_freq = 0;
  std::string max_account = "";

  for (const auto& [ip, account] : connections) { 
    if (hashmap.find(account) != hashmap.end()) {
      hashmap[account] += 1;
    } else {
      hashmap[account] = 1;
    }

    if (hashmap[account] > max_freq) {
      max_freq = hashmap[account];
      max_account = account;
    }
  }

  return max_account;
}

int main() {
  std::vector<std::pair<std::string, std::string>> connections = {
    {"203.0.113.10", "mike"},
    {"208.51.100.25", "bob"},
    {"202.0.2.5", "mike"},
    {"203.0.113.15", "bob2"}
  };

  std::cout << most_shared_account(connections) << std::endl;

  return 0;
}