#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <utility>

std::string account_sharing_detection(const std::vector<std::pair<std::string, std::string>>& connections) {
  std::unordered_set<std::string> hashset;

  for (const auto& connection : connections) {
    const std::string& ip = connection.first;
    const std::string& user = connection.second;

    if (hashset.find(user) != hashset.end()) {
      return ip;
    } else {
      hashset.insert(user);
    }
  }

  return "";
}

int main() {
    // Example1
    std::vector<std::pair<std::string, std::string>> connections1 = {
        {"203.0.113.10", "mike"},
        {"298.51.100.25", "bob"},
        {"292.0.2.5", "mike"},
        {"203.0.113.15", "bob2"}
    };
    std::cout << account_sharing_detection(connections1) << std::endl;

    // Example2
    std::vector<std::pair<std::string, std::string>> connections2 = {
        {"111.0.0.0", "mike"},
        {"111.0.0.1", "mike"},
        {"111.0.0.2", "bob"},
        {"111.0.0.3", "bob"}
    };
    std::cout << account_sharing_detection(connections2) << std::endl;

    // Example3
    std::vector<std::pair<std::string, std::string>> connections3 = {
        {"111.0.0.0", "mike"},
        {"111.0.0.1", "mike2"},
        {"111.0.0.2", "mike3"},
        {"111.0.0.3", "mike4"}
    };
    std::cout << account_sharing_detection(connections3) << std::endl;

    return 0;
}