#include <iostream>
#include <string>
#include <vector>

bool contains(const std::vector<int>& values, int target) {
    for (int value : values) {
        if (value == target) {
            return true;
        }
    }

    return false;
}

void backtrack(const std::string& num, int n, std::vector<int>& result) {
    int current = stoi(num);

    if (!contains(result, current) && current < n) {
        result.push_back(current);

        int last_digit = num.back() - '0';
        if (last_digit > 0) {
            backtrack(std::string(1, num.back()) + std::to_string(last_digit - 1), n, result);
        }

        if (last_digit < 9) {
            backtrack(std::string(1, num.back()) + std::to_string(last_digit + 1), n, result);
        }
    }
}

std::vector<int> jumping_numbers(int n) {
    std::vector<int> result;

    for (int i = 1; i < 10; i++) {
        backtrack(std::to_string(i), n, result);
    }

    return result;
}

int main() {
    int n = 34;
    std::vector<int> result = jumping_numbers(n);

    std::cout << "[";
    for (std::size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i + 1 < result.size()) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
