#include <iostream>
#include <string>
#include <vector>

std::vector<int> channel_views(std::vector<int>& views, std::vector<std::vector<int>>& periods) {
  std::vector<int> prefix_sums;
  std::vector<int> output;
  int previous_val = 0;

  for (int view: views) {
    previous_val += view;
    prefix_sums.push_back(previous_val);
  }

  for (const std::vector<int>& period: periods) {
    int start = period[0];
    int end = period[1];
    if (start == 0) {
      output.push_back(prefix_sums[end]);
    }else {
      output.push_back(prefix_sums[end] - prefix_sums[start-1]);
    }
  }

  return output;
}

int main() {
  std::vector<int> views = {3, 5, 4, 8, 7, 2, 5, 3, 2, 3};
  std::vector<std::vector<int>> periods = {{0, 1}, {0, 5}, {5, 8}, {3, 3}};

  std::vector<int> result = channel_views(views, periods);

  std::cout << "[";
  for (size_t i = 0; i < result.size(); i++) {
    std::cout << result[i];
    if (i < result.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;

  return 0;
}

