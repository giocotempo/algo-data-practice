#include <iostream>
#include <functional>

int cctv_footage(std::function<bool(int)> is_stolen, int t1, int t2) {
  while (t2 - t1 > 1) {
    int m = (t1 + t2) / 2;
    if (is_stolen(m)) {
      t2 = m;
    } else {
      t1 = m;
    }
  }

  return t2;
}

int main() {
  std::function<bool(int)> is_stolen = [](int t) { return t >= 5; };
  int t1 = 0;
  int t2 = 10;
  std::cout << cctv_footage(is_stolen, t1, t2) << std::endl;

  is_stolen = [](int t) { return t >= 6; };
  t1 = 0;
  t2 = 10;
  std::cout << cctv_footage(is_stolen, t1, t2) << std::endl;

  is_stolen = [](int t) { return t >= 3; };
  t1 = 0;
  t2 = 10;
  std::cout << cctv_footage(is_stolen, t1, t2) << std::endl;

  return 0;
}
