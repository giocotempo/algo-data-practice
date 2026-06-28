#include <iostream>
#include <vector>
#include <numeric>

bool smaller_prefixes(const std::vector<int>& arr) {
    int n = arr.size();
    for (int k = 1; k <= n / 2; k++) {
        int sum_k = std::accumulate(arr.begin(), arr.begin() + k, 0);
        int sum_2k = std::accumulate(arr.begin(), arr.begin() + 2 * k, 0);
        if (sum_k >= sum_2k) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> arr1 = {1, 2, 2, -1};
    std::cout << std::boolalpha << smaller_prefixes(arr1) << std::endl;

    std::vector<int> arr2 = {1, 2, -2, 1, 3, 5};
    std::cout << std::boolalpha << smaller_prefixes(arr2) << std::endl;

    return 0;
}
