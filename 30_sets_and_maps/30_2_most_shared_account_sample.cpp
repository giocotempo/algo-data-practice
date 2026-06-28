#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string most_shared_account(const vector<pair<string, string>>& connections) {
  unordered_map<string, int> hashmap;
  int max_freq = 0;
  string max_account = "";

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
  vector<pair<string, string>> connections = {
    {"203.0.113.10", "mike"},
    {"208.51.100.25", "bob"},
    {"202.0.2.5", "mike"},
    {"203.0.113.15", "bob2"}
  };

  cout << most_shared_account(connections) << endl;

  return 0;
}
