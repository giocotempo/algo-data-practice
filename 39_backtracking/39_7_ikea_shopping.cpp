#include <iostream>
#include <vector>

bool contains(const std::vector<int>& values, int target) {
    for (int value : values) {
        if (value == target) {
            return true;
        }
    }
    return false;
}

void back_track(
    int budget,
    const std::vector<int>& prices,
    const std::vector<double>& ratings,
    std::vector<int>& result,
    std::vector<int>& current,
    double& current_max,
    int& current_total_price,
    double& current_total_rating) {
    for (std::size_t i = 0; i < prices.size(); i++) {
        if (!contains(current, static_cast<int>(i))) {
            current.push_back(static_cast<int>(i));
            current_total_price += prices[i];
            current_total_rating += ratings[i];

            if (current_total_price < budget) {
                back_track(
                    budget,
                    prices,
                    ratings,
                    result,
                    current,
                    current_max,
                    current_total_price,
                    current_total_rating);
            }

            if (current_total_price <= budget && current_total_rating > current_max) {
                current_max = current_total_rating;
                result = current;
            }

            current.pop_back();
            current_total_rating -= ratings[i];
            current_total_price -= prices[i];
        }
    }
}

std::vector<int> ikea_shopping(
    int budget,
    const std::vector<int>& prices,
    const std::vector<double>& ratings) {
    std::vector<int> result;
    std::vector<int> current;
    double current_max = 0.0;
    int current_total_price = 0;
    double current_total_rating = 0.0;

    back_track(
        budget,
        prices,
        ratings,
        result,
        current,
        current_max,
        current_total_price,
        current_total_rating);

    return result;
}

void print_vector(const std::vector<int>& values) {
    std::cout << "[";
    for (std::size_t i = 0; i < values.size(); ++i) {
        std::cout << values[i];
        if (i + 1 < values.size()) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    int budget = 20;
    std::vector<int> prices = {10, 5, 15, 8, 3};
    std::vector<double> ratings = {7.0, 3.5, 9.0, 6.0, 2.0};
    print_vector(ikea_shopping(budget, prices, ratings));

    budget = 10;
    prices = {2, 3, 4, 5};
    ratings = {1.0, 2.0, 3.5, 4.0};
    print_vector(ikea_shopping(budget, prices, ratings));

    return 0;
}
