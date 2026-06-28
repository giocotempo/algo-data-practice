#include <iostream>
#include <vector>

std::vector<int> merge_two_sorted_arrays(std::vector<int> arr1, std::vector<int> arr2) {
    std::vector<int> output;
    int l = 0, r = 0;

    while (l < arr1.size() || r < arr2.size()) {
        if (l == arr1.size()) {
            output.push_back(arr2[r]);
            r++;
        }
        else if (r == arr2.size()) {
            output.push_back(arr1[l]);
            l++;
        }
        else {
            if (arr1[l] <= arr2[r]) {
                output.push_back(arr1[l]);
                l++;
            }
            else if (arr1[l] > arr2[r]) {
                output.push_back(arr2[r]);
                r++;
            }
        }
    }

    return output;
}

int main() {
    // Example1
    std::vector<int> arr1 = {1, 3, 4, 5};
    std::vector<int> arr2 = {2, 4, 4};
    std::vector<int> result1 = merge_two_sorted_arrays(arr1, arr2);

    std::cout << "[";
    for (size_t i = 0; i < result1.size(); i++) {
        std::cout << result1[i];
        if (i < result1.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    // Example2
    std::vector<int> arr3 = {-1};
    std::vector<int> arr4 = {};
    std::vector<int> result2 = merge_two_sorted_arrays(arr3, arr4);

    std::cout << "[";
    for (size_t i = 0; i < result2.size(); i++) {
        std::cout << result2[i];
        if (i < result2.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
