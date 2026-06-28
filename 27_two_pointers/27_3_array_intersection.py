def array_intersection(arr1: list[int], arr2: list[int])->list[int]:
  output = []
  p1, p2 = 0, 0

  while p1 < len(arr1) and p2 < len(arr2):
    if arr1[p1] == arr2[p2]:
      output.append(arr1[p1])
      p1 += 1
      p2 += 1
    elif arr1[p1] < arr2[p2]:
      p1 += 1
    elif arr1[p1] > arr2[p2]:
      p2 += 1

  return output


if __name__ == "__main__":
  arr1 = [1, 2, 3]
  arr2 = [1, 3, 5]
  print(array_intersection(arr1, arr2))

  arr1 = [1, 1, 1]
  arr2 = [1, 1]
  print(array_intersection(arr1, arr2))