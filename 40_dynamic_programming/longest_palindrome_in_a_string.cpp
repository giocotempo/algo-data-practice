#include <functional>
#include <iostream>
#include <string>
#include <vector>

std::string longest_palindrome_in_a_string(const std::string& s) {
    if (s.empty()) {
        return "";
    }

    std::vector<std::vector<int>> memo(
        s.size(),
        std::vector<int>(s.size(), -1)
    );

    for (std::size_t i = 0; i < s.size(); i++) {
        memo[i][i] = 1;
    }

    std::string longest_palindrome;

    std::function<bool(int, int)> rec = [&](int i, int j) -> bool {
        if (i > j) {
            return true;
        }

        if (memo[i][j] != -1) {
            return memo[i][j] == 1;
        }

        if (s[i] == s[j]) {
            memo[i][j] = rec(i+1, j-1) ? 1 : 0;
            if (memo[i][j] == 1 &&
            j - 1 + 1 > static_cast<int>(longest_palindrome.size())) {
                longest_palindrome = s.substr(i, j - i + 1);
            }
        } else {
            memo[i][j] = 0;
        }
        return memo[i][j] == 1;
    };

    for (std::size_t i = 0; i < s.size(); i++) {
        for (std::size_t j = i; j < s.size(); j++) {
            rec(static_cast<int>(i), static_cast<int>(j));
        }
    }

    return longest_palindrome;
}

int main() {
    std::string s = "abccbaba";
    std::cout << longest_palindrome_in_a_string(s) << std::endl;

    s = "abccbccbagf";
    std::cout << longest_palindrome_in_a_string(s) << std::endl;

    return 0;
}