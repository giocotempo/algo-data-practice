#include <iostream>
#include <vector>

bool time_traveler(const std::vector<int>& jumping_points, int k, int max_aging) {
    for (int i = 0; i < static_cast<int>(jumping_points.size()) - 1; i++) {
        int time_diff = jumping_points[i + 1] - jumping_points[i];
        if (time_diff >= max_aging) {
            if (k > 0) {
                k--;
            } else {
                max_aging -= time_diff;
            }
        } else {
            max_aging -= time_diff;
        }
    }

    return max_aging >= 0;
}

int main() {
    // Example1
    std::vector<int> jumping_points1 = {2020, 2024};
    int k1 = 0;
    int max_aging1 = 3;
    std::cout << time_traveler(jumping_points1, k1, max_aging1) << std::endl;

    // Example2
    std::vector<int> jumping_points2 = {2020, 2024};
    int k2 = 1;
    int max_aging2 = 1;
    std::cout << time_traveler(jumping_points2, k2, max_aging2) << std::endl;

    // Example3
    std::vector<int> jumping_points3 = {1803, 1861, 1863, 1865, 1920, 1929, 1941, 1964, 2001, 2021};
    int k3 = 4;
    int max_aging3 = 45;
    std::cout << time_traveler(jumping_points3, k3, max_aging3) << std::endl;

    return 0;
}
