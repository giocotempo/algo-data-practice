#include <iostream>
#include <string>

std::string robot_instructions(std::string seq) {
  if (seq.find("2") == std::string::npos) {
    return seq;
  }

  if (seq.find("2") != std::string::npos && seq.length() == 2) {
    return seq.substr(1);
  }

  size_t index = seq.find("2");
  std::string first_half, second_half;

  if (index == 0) {
    first_half = seq.substr(1);
    second_half = seq.substr(2);
  } else {
    first_half = seq.substr(0, index);
    second_half = seq.substr(index);
  }

  return robot_instructions(first_half) + robot_instructions(second_half);
}

int main() {
  // Example1
  std::string seq = "LL";
  std::cout << robot_instructions(seq) << std::endl;

  // Example2
  seq = "2LR";
  std::cout << robot_instructions(seq) << std::endl;

  // Example3
  seq = "2L";
  std::cout << robot_instructions(seq) << std::endl;

  // Example4
  seq = "22LR";
  std::cout << robot_instructions(seq) << std::endl;

  // Example5
  seq = "LL2R2L";
  std::cout << robot_instructions(seq) << std::endl;

  return 0;
}