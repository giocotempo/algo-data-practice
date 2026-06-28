#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <utility>

class TopSongs {
  public:
    explicit TopSongs(int k) : k_(k) {}
  
    void registerPlays(const std::string& title, int plays) {
      int newPlays = plays;
      auto it = plays_.find(title);
      if (it != plays_.end()) {
        newPlays = it->second + plays;
        plays_[title] = newPlays;
      } else {
        plays_[title] = plays;
      }

      heap_.push(std::make_pair(newPlays, title));
    }

    std::vector<std::string> topK() {
      std::vector<std::string> topSongs;
      topSongs.reserve(k_);

      while (static_cast<int>(topSongs.size()) < k_ && !heap_.empty()) {
        std::pair<int, std::string> item = heap_.top();
        heap_.pop();

        int plays = item.first;
        const std::string& title = item.second;

        if (plays_[title] == plays) {
          topSongs.push_back(title);
        }
      }

      return topSongs;
    }

  private:
    int k_;
    std::unordered_map<std::string, int> plays_;
    std::priority_queue<std::pair<int, std::string>> heap_;
};

int main() {
    TopSongs s(3);
    s.registerPlays("Boolean Rhapsody", 100);
    s.registerPlays("Boolean Rhapsody", 193);  // Total 293
    s.registerPlays("Coding In The Deep", 75);
    s.registerPlays("Coding In The Deep", 75);  // Total 150
    s.registerPlays("All About That Base Case", 200);
    s.registerPlays("All About That Base Case", 90);  // Total 290
    s.registerPlays("All About That Base Case", 1);   // Total 291
    s.registerPlays("Here Comes The Bug", 223);
    s.registerPlays("Oops! I Broke Prod Again", 274);
    s.registerPlays("All the Single Brackets", 132);

    std::vector<std::string> topSongs = s.topK();
    std::cout << "[";
    for (size_t i = 0; i < topSongs.size(); ++i) {
        std::cout << "'" << topSongs[i] << "'";
        if (i < topSongs.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
