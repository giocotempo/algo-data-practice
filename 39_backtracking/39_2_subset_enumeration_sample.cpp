#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

void back_track(const std::vector<std::string>& S, std::set<std::string>& candidates, std::vector<std::set<std::string>>& output) {
    // Check if candidates is not already in output
    if (std::find(output.begin(), output.end(), candidates) == output.end()) {
        output.push_back(candidates);
    }

    if (candidates.size() == S.size()) {
        return;
    }

    for (const std::string& s : S) {
        if (candidates.find(s) == candidates.end()) {
            candidates.insert(s);
            back_track(S, candidates, output);
            candidates.erase(s);
        }
    }
}

std::vector<std::vector<std::string>> subset_enumeration(const std::vector<std::string>& S) {
    std::set<std::string> candidates;
    std::vector<std::set<std::string>> output;
    back_track(S, candidates, output);

    // Convert vector<set<string>> to vector<vector<string>>
    std::vector<std::vector<std::string>> result;
    for (const auto& s : output) {
        std::vector<std::string> temp(s.begin(), s.end());
        result.push_back(temp);
    }
    return result;
}

int main() {
    // Example
    std::vector<std::string> S = {"x", "y", "z"};
    std::vector<std::vector<std::string>> result = subset_enumeration(S);

    // Print result
    std::cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            std::cout << "'" << result[i][j] << "'";
            if (j < result[i].size() - 1) std::cout << ", ";
        }
        std::cout << "]";
        if (i < result.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
