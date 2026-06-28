#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

class TopSongs {
private:
  int k;
  std::vector<std::pair<int, std::string>> heap;

public:
  TopSongs(int k) : k(k) {}

  void register_plays(const std::string& title, int plays) {
    heap.push_back(std::make_pair(plays, title));
    std::push_heap(heap.begin(), heap.end());
  }

  std::vector<std::string> top_k() {
    std::vector<std::pair<int, std::string>> temp = heap;
    std::sort_heap(temp.begin(), temp.end());

    std::vector<std::string> result;
    int count = std::min(k, static_cast<int>(temp.size()));

    for (int i = temp.size() - 1; i >= temp.size() - count; --i) {
      result.push_back(temp[i].second);
    }

    return result;
  }
};

int main() {
  TopSongs s(3);
  s.register_plays("Boolean Rhapsody", 193);
  s.register_plays("Coding In The Deep", 146);

  std::vector<std::string> top = s.top_k();
  std::cout << "[";
  for (size_t i = 0; i < top.size(); ++i) {
    std::cout << "'" << top[i] << "'";
    if (i < top.size() - 1) std::cout << ", ";
  }
  std::cout << "]" << std::endl;

  s.register_plays("All About That Base Case", 291);
  s.register_plays("Here Comes The Bug", 223);
  s.register_plays("Oops! I Broke Prod Again", 274);
  s.register_plays("All the Single Brackets", 132);

  top = s.top_k();
  std::cout << "[";
  for (size_t i = 0; i < top.size(); ++i) {
    std::cout << "'" << top[i] << "'";
    if (i < top.size() - 1) std::cout << ", ";
  }
  std::cout << "]" << std::endl;

  return 0;
}
