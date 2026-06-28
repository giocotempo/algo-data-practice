def robot_instructions(seq: str)->str:
  # Base Case1
  if "2" not in seq:
    return seq
  # Base Case2
  if "2" in seq and len(seq) == 2:
    return seq[1]

  index = seq.find("2")
  if index == 0:
    first_half = seq[1:]
    second_half = seq[2:]
  else:
    first_half = seq[:index]
    second_half = seq[index:]

  return robot_instructions(first_half) + robot_instructions(second_half)

if __name__ == "__main__":
  # Example1
  seq = "LL"
  print(robot_instructions(seq))
  # Example2
  seq = "2LR"
  print(robot_instructions(seq))
  # Example3
  seq = "2L"
  print(robot_instructions(seq))
  # Example4
  seq = "22LR"
  print(robot_instructions(seq))
  # Example5
  seq = "LL2R2L"
  print(robot_instructions(seq))