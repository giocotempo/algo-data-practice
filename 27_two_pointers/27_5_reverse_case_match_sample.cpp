#include <iostream>
#include <string>
#include <cctype>

bool reverse_case_match(const std::string& s) {
    int l = 0;
    int r = s.length() - 1;
    std::string lower_letters;
    std::string upper_letters;

    while (l < s.length()) {
        if (std::islower(s[l])) {
            lower_letters += s[l];
        }
        if (std::isupper(s[r])) {
            upper_letters += std::tolower(s[r]);
        }

        l++;
        r--;
    }

    return lower_letters == upper_letters;
}

int main() {
    std::string s = "haDrRAHd";
    std::cout << std::boolalpha << reverse_case_match(s) << std::endl;

    s = "haHrARDd";
    std::cout << std::boolalpha << reverse_case_match(s) << std::endl;

    return 0;
}
