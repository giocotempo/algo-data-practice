def search_sorted_array(arr: list, target: int)->int:
  if len(arr) == 0:
    return -1
  if len(arr) == 1:
    if arr[0] == target:
      return 0
    else:
      return -1

  l, r = 0, len(arr) - 1

  while r - l > 1:
    m = (l + r) // 2
    if arr[m] == target:
      return m
    
    if arr[m] > target:
      r = m
    else:
      l = m
  
  return -1

if __name__ == "__main__":
  # Example1
  arr = [-2, 0, 3, 4, 7, 9, 11]
  target = 3
  print(search_sorted_array(arr, target))

  # Example2
  arr = [-2, 0, 3, 4, 7, 9, 11]
  target = 2
  print(search_sorted_array(arr, target))