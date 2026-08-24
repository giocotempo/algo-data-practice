#include <cstddef>
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

std::uint64_t sum_of_first_k_prime_powers(
    const std::vector<int>& primes,
    int k) {
    if (k <= 0 || primes.empty()) {
        return 0;
    }

    std::priority_queue<std::uint64_t> max_heap;
    std::vector<std::uint64_t> powers(primes.size(), 1);

    for (int exponent = 1; exponent <= k; ++exponent) {
        bool is_updated = false;

        for (std::size_t i = 0; i < primes.size(); ++i) {
            powers[i] *= primes[i];
            const std::uint64_t power = powers[i];

            if (max_heap.size() < static_cast<std::size_t>(k)) {
                max_heap.push(power);
                is_updated = true;
            } else if (max_heap.top() > power) {
                max_heap.pop();
                max_heap.push(power);
                is_updated = true;
            }
        }

        if (!is_updated) {
            break;
        }
    }

    std::uint64_t sum = 0;
    while (!max_heap.empty()) {
        sum += max_heap.top();
        max_heap.pop();
    }

    return sum;
}

int main() {
    // Example 1
    std::vector<int> primes = {2};
    int k = 1;
    std::cout << sum_of_first_k_prime_powers(primes, k) << '\n';

    // Example 2
    primes = {5};
    k = 3;
    std::cout << sum_of_first_k_prime_powers(primes, k) << '\n';

    // Example 3
    primes = {2, 3};
    k = 7;
    std::cout << sum_of_first_k_prime_powers(primes, k) << '\n';

    return 0;
}
