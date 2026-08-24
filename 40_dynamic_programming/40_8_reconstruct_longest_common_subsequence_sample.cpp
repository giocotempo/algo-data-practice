#include <iostream>
#include <string>
#include <vector>

std::string reconstruct_longest_common_subsequence(
    const std::string& s1,
    const std::string& s2
) {
    std::vector<std::vector<std::string> > dp(
        s1.size() + 1,
        std::vector<std::string>(s2.size() + 1, "")
    );

    for (std::size_t i = 0; i < s1.size(); i++) {
        for (std::size_t j = 0; j < s2.size(); j++) {
            if (s1[i] == s2[j]) {
                dp[i + 1][j + 1] = dp[i][j] + s1[i];
            } else if (dp[i + 1][j].size() >= dp[i][j + 1].size()) {
                dp[i + 1][j + 1] = dp[i + 1][j];
            } else {
                dp[i + 1][j + 1] = dp[i][j + 1];
            }
        }
    }

    return dp[s1.size()][s2.size()];
}

int main() {
    // Example 1
    std::string s1 = "HAHAH";
    std::string s2 = "AAAAHH";
    std::cout << reconstruct_longest_common_subsequence(s1, s2) << std::endl;

    // Example 2
    s1 = "";
    s2 = "AA";
    std::cout << reconstruct_longest_common_subsequence(s1, s2) << std::endl;

    return 0;
}
