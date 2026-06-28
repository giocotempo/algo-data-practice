#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

void back_track(const std::vector<std::string>& arr, std::vector<std::string>& candidates, std::unordered_set<std::string>& used, std::vector<std::vector<std::string>>& output) {
  if (candidates.size() == arr.size()) {
    output.push_back(candidates);
    return;
  }

  for (const std::string& n : arr) {
    if (used.find(n) == used.end()) {
      used.insert(n);
      candidates.push_back(n);

      back_track(arr, candidates, used, output);

      used.erase(n);
      candidates.pop_back();
    }
  }
}

std::vector<std::vector<std::string>> permutation_enumeration(const std::vector<std::string>& arr) {
  std::vector<std::vector<std::string>> output;
  std::vector<std::string> candidates;
  std::unordered_set<std::string> used;
  back_track(arr, candidates, used, output);
  return output;
} 

int main() {
    // Example1
    std::vector<std::string> arr1 = {"x", "y", "z"};
    std::vector<std::vector<std::string>> result1 = permutation_enumeration(arr1);

    std::cout << "[";
    for (size_t i = 0; i < result1.size(); i++) {
        std::cout << "[";
        for (size_t j = 0; j < result1[i].size(); j++) {
            std::cout << "'" << result1[i][j] << "'";
            if (j < result1[i].size() - 1) std::cout << ", ";
        }
        std::cout << "]";
        if (i < result1.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    // Example2
    std::vector<std::string> arr2 = {"x"};
    std::vector<std::vector<std::string>> result2 = permutation_enumeration(arr2);

    std::cout << "[";
    for (size_t i = 0; i < result2.size(); i++) {
        std::cout << "[";
        for (size_t j = 0; j < result2[i].size(); j++) {
            std::cout << "'" << result2[i][j] << "'";
            if (j < result2[i].size() - 1) std::cout << ", ";
        }
        std::cout << "]";
        if (i < result2.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
