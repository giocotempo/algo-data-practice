def count_subarrays_with_sum_k(arr: list[int], k: int)->int:
  count = 0
  l, r = 0, 0
  
  while r < len(arr):
    if sum(arr[l:r + 1]) == k:
      count += 1
      l += 1
    elif sum(arr[l:r + 1]) > k:
      l += 1
    else:
      r += 1
  
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