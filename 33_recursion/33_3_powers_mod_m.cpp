#include <iostream>

int powers_mod_m(int a, int p, int m) {
  if (p == 0) {
    return 1;
  }

  int mod = a * powers_mod_m(a, p - 1, m) % m;
  return mod;
}

int main() {
  // Example1
  int a = 2;
  int p = 5;
  int m = 100;
  std::cout << powers_mod_m(a, p, m) << std::endl;

  // Example2
  a = 2;
  p = 5;
  m = 30;
  std::cout << powers_mod_m(a, p, m) << std::endl;

  return 0;
}