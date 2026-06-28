def parity_sorting(arr: list[int])->list[int]:
  l, r = 0, len(arr)-1
  while l<r:
    if arr[l] % 2 == 1 and arr[r] % 2 == 0:
      arr[l], arr[r] = arr[r], arr[l]
      l += 1
      r -= 1
    elif arr[l] % 2 == 0 and arr[r] % 2 == 1:
      l += 1
      r -= 1
    elif arr[l] % 2 == 0 and arr[r] % 2 == 0:
      l += 1
    else:
      r -= 1
  
  return arr

if __name__ == "__main__":
  # Example1
  arr = [1, 2, 3, 4, 5]
  print(parity_sorting(arr))
  # Example2
  arr = [5, 1, 3, 1, 5]
  print(parity_sorting(arr))
  # Example3
  arr = [1, 4, 5, 2, 6, 8, 7, 10]
  print(parity_sorting(arr))