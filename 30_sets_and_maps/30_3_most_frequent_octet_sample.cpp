#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::string most_frequent_octet(const std::vector<std::string>& ips) {
  std::unordered_map<std::string, int> hashmap;

  for (const std::string& ip : ips) {
    std::string first_octet = ip.substr(0, ip.find("."));
    hashmap[first_octet]++;
  }

  std::string max_octet = "";
  int max_count = 0;

  for (const auto& [octet, count] : hashmap) {
    if (count > max_count) {
      max_octet = octet;
      max_count = count;
    }
  }

  return max_octet;
}

int main() {
  std::vector<std::string> ips = {"203.0.113.10", "208.51.100.5", "202.0.2.5", "203.0.113.5"};
  std::cout << most_frequent_octet(ips) << std::endl;
  return 0;
}
