#include <iostream>
#include <vector>
#include <deque>

int maximum_with_at_most_3_bad_days(const std::vector<int>& sales) {
  if (sales.size() <= 3) {
    return sales.size();
  }

  int l = 0, r = 1;
  int maximum = 0;
  std::deque<int> bad_day_pointers;
  int bad_days;

  if (sales[0] < 10) {
    bad_days = 1;
    bad_day_pointers.push_back(0);
  } else {
    bad_days = 0;
  }

  while (r < sales.size()) {
    if (sales[r] < 10) {
      bad_days++;
      bad_day_pointers.push_back(r);
    }

    if (bad_days > 3) {
      int bad_day_left = bad_day_pointers.front();
      bad_day_pointers.pop_front();
      bad_days--;
      l = bad_day_left + 1;
    } else if (r - l + 1 > maximum) {
      maximum = r - l + 1;
    }

    r++;
  }

  return maximum;
}

int main() {
  std::vector<int> sales = {0, 14, 7, 9, 0, 20, 10, 0, 10};
  std::cout << maximum_with_at_most_3_bad_days(sales) << std::endl;
  return 0;
}
