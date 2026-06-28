#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> array_reversal(std::vector<std::string>& arr) {
    int l = 0;
    int r = arr.size() - 1;

    while (l < r) {
        std::swap(arr[l], arr[r]);
        l++;
        r--;
    }

    return arr;
}

int main() {
    std::vector<std::string> arr1;
    arr1.push_back("a");
    arr1.push_back("b");
    arr1.push_back("c");
    arr1.push_back("d");
    arr1.push_back("f");
    arr1.push_back("g");
    arr1.push_back("h");
    array_reversal(arr1);
    std::cout << "[";
    for (size_t i = 0; i < arr1.size(); i++) {
        std::cout << "'" << arr1[i] << "'";
        if (i < arr1.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    std::vector<std::string> arr2;
    arr2.push_back("b");
    arr2.push_back("c");
    arr2.push_back("t");
    arr2.push_back("c");
    arr2.push_back("i");
    array_reversal(arr2);
    std::cout << "[";
    for (size_t i = 0; i < arr2.size(); i++) {
        std::cout << "'" << arr2[i] << "'";
        if (i < arr2.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
