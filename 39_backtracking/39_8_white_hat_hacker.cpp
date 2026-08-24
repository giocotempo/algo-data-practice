#include <iostream>
#include <string>
#include <vector>

const std::string CORRECT_PASSWORD = "bc";

bool check_password(const std::string& password) {
    return password == CORRECT_PASSWORD;
}

bool contains(const std::vector<char>& values, char target) {
    for (char value : values) {
        if (value == target) {
            return true;
        }
    }

    return false;
}

bool backtrack(
    int max_length,
    const std::vector<char>& elements,
    std::vector<char>& current,
    std::string& result) {
        if (static_cast<int>(current.size()) >= max_length) {
            return false;
        }

        for (char element : elements) {
            if (!contains(current, element)) {
                current.push_back(element);

                std::string candidate(current.begin(), current.end());
                if (check_password(candidate)) {
                    result = candidate;
                    return true;
                }

                if (backtrack(max_length, elements, current, result)) {
                    return true;
                }

                current.pop_back();
            }
        }

        return false;
    }

    std::string white_hat_hacker(int max_length) {
    std::vector<char> elements = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    std::vector<char> current;
    std::string result;

    backtrack(max_length, elements, current, result);

    return result;
}

int main() {
    std::cout << white_hat_hacker(4) << std::endl;
    return 0;
}