#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

bool enduring_best_seller_streak(std::vector<std::string>& best_seller, int k) {
  int l = 0, r = 0;
  int cur = 0;
  std::unordered_map<std::string, int> hashmap;

  while (r < best_seller.size()) {
    if (hashmap.find(best_seller[r]) == hashmap.end()) {
      hashmap[best_seller[r]] = 0;
    }
    hashmap[best_seller[r]] += 1;
    cur += 1;

    if (cur == k) {
      if (hashmap[best_seller[r]] == k) {
        return true;
      }

      hashmap[best_seller[l]] -= 1;
      l += 1;
      cur -= 1;
    }

    r += 1;
  }
  return false;
}

int main() {
    std::vector<std::string> best_seller = {"book3", "book1", "book3", "book3", "book2"};
    int k = 3;
    std::cout << (enduring_best_seller_streak(best_seller, k) ? "true" : "false") << std::endl;

    best_seller = {"book3", "book1", "book3", "book3", "book2"};
    k = 2;
    std::cout << (enduring_best_seller_streak(best_seller, k) ? "true" : "false") << std::endl;

    return 0;
}