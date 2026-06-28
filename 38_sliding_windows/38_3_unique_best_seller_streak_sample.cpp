#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool unique_best_seller_streak(vector<string> best_seller, int k) {
    int l = 0, r = 0;
    unordered_map<string, int> window_counts;

    while (r < best_seller.size()) {
        if (window_counts.find(best_seller[r]) == window_counts.end()) {
            window_counts[best_seller[r]] = 0;
        }
        window_counts[best_seller[r]] += 1;
        r += 1;

        if (r - l == k) {
            if (window_counts.size() == k) {
                return true;
            }
            window_counts[best_seller[l]] -= 1;
            if (window_counts[best_seller[l]] == 0) {
                window_counts.erase(best_seller[l]);
            }
            l += 1;
        }
    }
    return false;
}

int main() {
    vector<string> best_seller = {"book3", "book1", "book3", "book3", "book2", "book3", "book4", "book3"};
    int k = 3;
    cout << (unique_best_seller_streak(best_seller, k) ? "true" : "false") << endl;
    return 0;
}
