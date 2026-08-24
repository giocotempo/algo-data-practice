#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int longest_common_subsequence(const std::string& s1, const std::string& s2) {
    std::vector<std::vector<int>> dp (
        s1.size() + 1,
        std::vector<int>(s2.size() + 1, 0)
    );

    for (std::size_t i = 0; i < s1.size(); i++) {
        for (std::size_t j = 0; j < s2.size(); j++) {
            if (s1[i] == s2[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            } else {
                dp[i+1][j+1] = std::max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }

    return dp[s1.size()][s2.size()];
}

int main() {
    // Example 1
    std::string s1 = "HAHAH";
    std::string s2 = "AAAAHH";
    std::cout << longest_common_subsequence(s1, s2) << std::endl;

    // Example 2
    s1 = "";
    s2 = "AA";
    std::cout << longest_common_subsequence(s1, s2) << std::endl;

    // Example 3
    s1 = "ABCBDAB";
    s2 = "BDCABA";
    std::cout << longest_common_subsequence(s1, s2) << std::endl;

    return 0;
}
