#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> exclusive_product(const std::vector<int>& arr) {
    if (std::find(arr.begin(), arr.end(), 0) != arr.end()) {
        return std::vector<int>(arr.size(), 0);
    }

    int all_product = 1;
    for (int n : arr) {
        all_product *= n;
    }

    std::vector<int> output;
    for (int n : arr) {
        int exclusive_product_val = all_product / n;
        output.push_back(exclusive_product_val);
    }

    return output;
}

int main() {
    // Example1
    std::vector<int> arr1 = {1, 3, 2, 1};
    std::vector<int> result1 = exclusive_product(arr1);
    std::cout << "[";
    for (size_t i = 0; i < result1.size(); i++) {
        std::cout << result1[i];
        if (i < result1.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    // Example2
    std::vector<int> arr2 = {0, 1, 0};
    std::vector<int> result2 = exclusive_product(arr2);
    std::cout << "[";
    for (size_t i = 0; i < result2.size(); i++) {
        std::cout << result2[i];
        if (i < result2.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
