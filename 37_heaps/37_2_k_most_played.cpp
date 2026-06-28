#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> k_most_played(const std::vector<std::pair<std::string, int>>& songs, int k) {
  std::vector<std::pair<std::string, int>> songs_copy = songs;

  std::partial_sort(
    songs_copy.begin(),
    songs_copy.begin() + k,
    songs_copy.end(),
    [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
      return a.second > b.second;
    }
  );

  std::vector<std::string> result;
  for (int i = 0; i < k; i++) {
    result.push_back(songs_copy[i].first);
  }

  return result;
}

int main() {
  // Example
  std::vector<std::pair<std::string, int>> songs = {
    {"All the Single Brackets", 132},
    {"Oops! I Broke Prod Again", 274},
    {"Coding In The Deep", 146},
    {"Boolean Rhapsody", 193},
    {"Here Comes The Bug", 291},
    {"All About That Base Case", 291}
  };
  int k = 3;

  std::vector<std::string> result = k_most_played(songs, k);

  std::cout << "[";
  for (size_t i = 0; i < result.size(); i++) {
    std::cout << "\"" << result[i] << "\"";
    if (i < result.size() - 1) std::cout << ", ";
  }
  std::cout << "]\n";

  return 0;
}
