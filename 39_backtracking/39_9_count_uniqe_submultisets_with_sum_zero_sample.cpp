#include <iostream>
#include <unordered_map>
#include <vector>

void backtrack(
    const std::vector<int>& candidates,
    const std::unordered_map<int, int>& frequency_map,
    int start_index,
    int current_sum,
    int& result) {
    for (int i = start_index; i < static_cast<int>(candidates.size()); ++i) {
        int num = candidates[i];
        int frequency = frequency_map.at(num);

        for (int count = 1; count <= frequency; ++count) {
            int next_sum = current_sum + (num * count);

            if (next_sum == 0) {
                ++result;
            }

            backtrack(candidates, frequency_map, i + 1, next_sum, result);
        }
    }
}

int count_unique_submultisets_with_sum_zero(const std::vector<int>& values) {
    int result = 1;
    std::vector<int> candidates;
    std::unordered_map<int, int> frequency_map;

    for (int value : values) {
        if (frequency_map.find(value) == frequency_map.end()) {
            frequency_map[value] = 1;
            candidates.push_back(value);
        } else {
            ++frequency_map[value];
        }
    }

    backtrack(candidates, frequency_map, 0, 0, result);

    return result;
}

int main() {
    std::vector<int> values = {1, 1, -1, -1};
    std::cout << count_unique_submultisets_with_sum_zero(values) << std::endl;

    values = {};
    std::cout << count_unique_submultisets_with_sum_zero(values) << std::endl;

    values = {-1, 2, 1, 0, 3};
    std::cout << count_unique_submultisets_with_sum_zero(values) << std::endl;

    return 0;
}
