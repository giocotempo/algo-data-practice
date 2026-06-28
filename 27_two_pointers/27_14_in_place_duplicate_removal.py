import math

def in_place_duplicate_removal(arr: list[int])->int:
  writer, seeker = 0, 0
  cur_max = -math.inf
  while seeker < len(arr):
    if arr[writer] > cur_max:
      cur_max = arr[writer]
      writer += 1
      seeker += 1
    elif arr[seeker] > cur_max:
      arr[writer], arr[seeker] = arr[seeker], arr[writer]
      cur_max = arr[writer]
      writer += 1
      seeker += 1
    else:
      seeker += 1

  return writer

if __name__ == "__main__":
  # Example1
  arr = [1, 2, 2, 3, 3, 3, 5]
  print(in_place_duplicate_removal(arr))
  # Example2
  arr = [1, 3, 4, 4, 2, 5, 6, 6, 6, 8, 9, 10]
  print(in_place_duplicate_removal(arr))