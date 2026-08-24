#include <iostream>
#include <vector>

int maximum_subarray_sum(const std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    std::vector<std::vector<int>> dp (
        nums.size(),
        std::vector<int>(nums.size(), 0)
    );

    int res = 0;
    for (std::size_t i = 0; i < nums.size(); i++) {
        dp[i][i] = nums[i];
        res = std::max(res, dp[i][i]);
    }

    for (std::size_t i = 0; i < nums.size(); i++) {
        for (std::size_t j = i; j < nums.size(); j++) {
            dp[i][j] = dp[i][j-1] + nums[j];
            if (dp[i][j] > res) {
                res = dp[i][j];
            }
        }
    }

    return res;
}

int main() {
    std::vector<int> nums = {3, 1, -6, 2, -1, 4, -9};
    std::cout << maximum_subarray_sum(nums) << std::endl;

    return 0;
}