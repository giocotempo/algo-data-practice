#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

bool unique_best_seller_streak(std::vector<std::string>& best_seller, int k) {
  int l = 0, r = 0;
  std::unordered_map<std::string, int> window_counts;

  while (r < best_seller.size()) {
    if (window_counts.find(best_seller[r]) == window_counts.end()) {
      window_counts[best_seller[r]] = 0;
    }
    window_counts[best_seller[r]] += 1;
    r++;

    if (r - l == k) {
      if (window_counts.size() == k) {
        return true;
      }
      window_counts[best_seller[l]] -= 1;
      if (window_counts[best_seller[l]] == 0) {
        window_counts.erase(best_seller[l]);
      }
      l++;
    }
  }
  return false;
}

int main() {
    std::vector<std::string> best_seller = {"book3", "book1", "book3", "book3", "book2", "book3", "book4", "book3"};
    int k = 3;
    std::cout << (unique_best_seller_streak(best_seller, k) ? "true" : "false") << std::endl;
    return 0;
}