#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void back_track(int start, const std::vector<std::string>& candidates, std::vector<std::string>& used, std::vector<std::string>& output) {
  std::string outcome = "";
  for (size_t i = 0; i < used.size(); i++) {
    if (i > 0) outcome += " ";
    outcome += used[i];
  }

  if (std::find(output.begin(), output.end(), outcome) == output.end()) {
    output.push_back(outcome);
  }

  if (used.size() == candidates.size()) {
    return;
  }

  if (start > (int)candidates.size()) {
    return;
  }

  for (int i = start; i < (int)candidates.size(); i++) {
    std::string c = candidates[i];
    if (std::find(used.begin(), used.end(), c) == used.end()) {
      used.push_back(c);
      back_track(i + 1, candidates, used, output);
      used.pop_back();
    }
  }
}

std::vector<std::string> shakespearify(const std::string& sentence) {
  std::vector<std::string> letters;
  std::stringstream ss(sentence);
  std::string word;

  while (ss >> word) {
    letters.push_back(word);
  }

  std::vector<std::string> output;
  std::vector<std::string> used;
  back_track(0, letters, used, output);
  return output;
}

int main() {
    // Example
    std::string sentence = "I love dogs";
    std::vector<std::string> result = shakespearify(sentence);

    std::cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << "\"" << result[i] << "\"";
        if (i < result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}