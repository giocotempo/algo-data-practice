#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>

std::vector<std::string> most_listened_across_genre(
  const std::vector<std::vector<std::pair<std::string, int>>>& genres,
  int k
) {
  std::priority_queue<
    std::pair<int, std::string>,
    std::vector<std::pair<int, std::string>>,
    std::greater<std::pair<int, std::string>>
  > min_heap;

  for (const auto& genre : genres) {
    for (const auto& [title, play] : genre) {
      if (min_heap.size() < static_cast<size_t>(k)) {
        min_heap.push({play, title});
      } else {
        if (min_heap.top().first < play) {
          min_heap.pop();
          min_heap.push({play, title});
        }
      }
    }
  }

  std::vector<std::string> result;
  while (!min_heap.empty()) {
    result.push_back(min_heap.top().second);
    min_heap.pop();
  }
  std::reverse(result.begin(), result.end());

  return result;
}

int main() {
    std::vector<std::vector<std::pair<std::string, int>>> genres = {
        { // Pop
            {"Coding In The Deep", 123},
            {"Someone Like GNU", 99},
            {"Hello World", 98}
        },
        { // Country
            {"Ring Of Firewalls", 217}
        },
        { // Rock
            {"Boolean Rhapsody", 184},
            {"Merge Together", 119},
            {"Hey Queue", 102}
        }
    };

    int k = 5;
    auto result = most_listened_across_genre(genres, k);

    std::cout << "Top " << k << " songs across all genres:" << std::endl;
    for (const auto& title : result) {
        std::cout << title << std::endl;
    }

    return 0;
}
