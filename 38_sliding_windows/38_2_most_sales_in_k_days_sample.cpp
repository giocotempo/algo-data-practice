#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int most_sales_in_k_days(const vector<int>& sales, int k) {
    int l = 0, r = 0;
    int max_sales_index = -1;
    int max_sales = 0;

    while (r <= sales.size()) {
        r += 1;
        if (r - l == k) {
            int current_sum = accumulate(sales.begin() + l, sales.begin() + r, 0);
            if (current_sum > max_sales) {
                max_sales = current_sum;
                max_sales_index = l;
            }
            l += 1;
        }
    }

    return max_sales_index;
}

int main() {
    vector<int> sales = {8, 1, 3, 7};
    int k = 2;
    cout << most_sales_in_k_days(sales, k) << endl;
    return 0;
}
