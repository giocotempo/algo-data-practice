def exclusive_product(arr: list)->list:
  if 0 in arr:
    return [0] * len(arr)

  all_product = 1
  for n in arr:
    all_product *= n

  output = []
  for n in arr:
    exclusive_product = all_product // n
    output.append(exclusive_product)

  return output

if __name__ == "__main__":
  # Example1
  arr = [1, 3, 2, 1]
  print(exclusive_product(arr))
  # Example2
  arr = [0, 1, 0]
  print(exclusive_product(arr))
