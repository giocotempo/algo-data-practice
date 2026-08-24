def count_subarrays_with_sum_k(arr: list[int], k: int)->int:
  prefix_sum = [arr[0]]
  for i in range(1, len(arr)):
    prefix_sum.append(prefix_sum[i-1] + arr[i])

  count = 0
  for i in range(len(arr)):
    if prefix_sum[i] == k:
      count += 1
    for j in range(i):
      if prefix_sum[i] - prefix_sum[j] == k:
        count += 1
  
  return count

if __name__ == "__main__":
  # Example1
  arr = [1, 2, 3, 2, 1]
  k = 3
  print(count_subarrays_with_sum_k(arr, k))
  # Example2
  arr = [-1, -2, -3, 2, 1]
  k = -3
  print(count_subarrays_with_sum_k(arr, k))