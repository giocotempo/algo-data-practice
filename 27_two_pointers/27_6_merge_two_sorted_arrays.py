def merge_two_sorted_arrays(arr1: list[int], arr2: list[int])->list[int]:
  output = []
  l, r = 0, 0
  while l < len(arr1) or r < len(arr2):
    if l == len(arr1):
      output.append(arr2[r])
      r += 1
    elif r == len(arr2):
      output.append(arr1[l])
      l += 1
    else:
      if arr1[l] <= arr2[r]:
        output.append(arr1[l])
        l += 1
      elif arr1[l] > arr2[r]:
        output.append(arr2[r])
        r += 1
  
  return output


if __name__ == "__main__":
  # Example1
  arr1 = [1, 3, 4, 5]
  arr2 = [2, 4, 4]
  print(merge_two_sorted_arrays(arr1, arr2))
  # Example2
  arr1 = [-1]
  arr2 = []
  print(merge_two_sorted_arrays(arr1, arr2))

