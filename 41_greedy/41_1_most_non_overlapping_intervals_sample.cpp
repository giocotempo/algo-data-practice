#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int most_non_overlapping_intervals(std::vector<std::vector<int>>& intervals) {
    // Sort intervals by end time
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1];
    });

    int prev_end = std::numeric_limits<int>::min();
    int counter = 0;

    for (const auto& interval : intervals) {
        int l = interval[0];
        int r = interval[1];

        if (l > prev_end) {
            prev_end = r;
            counter++;
        }
    }

    return counter;
}

int main() {
    // Example1
    std::vector<std::vector<int>> intervals1 = {{2, 3}, {1, 4}, {2, 3}, {3, 6}, {8, 9}};
    std::cout << most_non_overlapping_intervals(intervals1) << std::endl;

    // Example2
    std::vector<std::vector<int>> intervals2 = {{1, 2}, {2, 3}, {3, 4}};
    std::cout << most_non_overlapping_intervals(intervals2) << std::endl;

    return 0;
}
