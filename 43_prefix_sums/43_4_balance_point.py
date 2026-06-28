def balance_point(arr: list) -> int:
  prefix_sum = []
  for i in range(len(arr)):
    if i == 0:
      prefix_sum.append(arr[0])
    else:
      prefix_sum.append(prefix_sum[i-1] + arr[i])
  
  for i in range(1, len(arr)-1):
    if prefix_sum[i-1] == (prefix_sum[-1] - prefix_sum[i]):
      return i
  return -1


if __name__ == "__main__":
  # Example
  arr = [3, 5, -2, 7, 2, 2, 2]
  print(balance_point(arr))