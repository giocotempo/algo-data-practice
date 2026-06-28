#include <iostream>
#include <vector>

std::vector<int> youtube_video_reception(const std::vector<int>* likes, const std::vector<int>* dislikes, const std::vector<std::vector<int>>* periods) {
  std::vector<int> prefix_sums;
  int cur_sum = 0;

  for (int i=0; i < likes->size(); i++) {
    if ((*likes)[i] - (*dislikes)[i] > 0) {
      cur_sum++;
    }
    prefix_sums.push_back(cur_sum);
  }

  std::vector<int> output;
  for (const auto& period: *periods) {
    int l = period[0];
    int r = period[1];
    if (l == 0) {
      output.push_back(prefix_sums[r]);
    } else {
      output.push_back(prefix_sums[r] - prefix_sums[l-1]);
    }
  }

  return output;
}

int main() {
  std::vector<int> likes = {6, 3, 4, 8, 7, 2, 6, 5, 0, 1};
  std::vector<int> dislikes = {6, 0, 8, 0, 0, 0, 1, 8, 0, 2};
  std::vector<std::vector<int>> periods = {{0, 1}, {0, 5}, {5, 8}, {3, 3}};

  std::vector<int> result = youtube_video_reception(&likes, &dislikes, &periods);

  std::cout << "[";
  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i];
    if (i < result.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;

  return 0;
}