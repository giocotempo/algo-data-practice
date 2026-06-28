#include <iostream>
#include <vector>
#include <variant>

struct NestedArray {
  std::variant<int, std::vector<NestedArray>> value;

  NestedArray(int v) : value(v) {}
  NestedArray(std::vector<NestedArray> v) : value(v) {}
};

int calc_array_sum(const std::vector<NestedArray>& nums) {
  int array_sum = 0;
  for (const auto& e : nums) {
    if (std::holds_alternative<std::vector<NestedArray>>(e.value)) {
      array_sum += calc_array_sum(std::get<std::vector<NestedArray>>(e.value));
    } else {
      array_sum += std::get<int>(e.value);
    }
  }
  return array_sum;
}

int nested_array_sum(const std::vector<NestedArray>& arr) {
  return calc_array_sum(arr);
}

int main() {
    // arr = [1, [2, 3], [4, [5]], 6]
    std::vector<NestedArray> arr1 = {
        NestedArray(1),
        NestedArray(std::vector<NestedArray>{2, 3}),
        NestedArray(std::vector<NestedArray>{
            NestedArray(4),
            NestedArray(std::vector<NestedArray>{5})
        }),
        NestedArray(6)
    };
    std::cout << nested_array_sum(arr1) << std::endl;

    // arr = [[[[1]], 2]]
    std::vector<NestedArray> arr2 = {
        NestedArray(std::vector<NestedArray>{
            NestedArray(std::vector<NestedArray>{
                NestedArray(std::vector<NestedArray>{
                    NestedArray(std::vector<NestedArray>{1})
                })
            }),
            NestedArray(2)
        })
    };
    std::cout << nested_array_sum(arr2) << std::endl;

    // arr = []
    std::vector<NestedArray> arr3 = {};
    std::cout << nested_array_sum(arr3) << std::endl;

    return 0;
}
