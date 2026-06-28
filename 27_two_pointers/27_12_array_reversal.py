def array_reversal(arr: list[str])->list[str]:
  l, r = 0, len(arr)-1
  while l<r:
    arr[l], arr[r] = arr[r], arr[l]
    l += 1
    r -= 1

  return arr

if __name__ == "__main__":
  arr = ["a", "b", "c", "d", "f", "g", "h"]
  print(array_reversal(arr))

  arr = ["b", "c", "t", "c", "i"]
  print(array_reversal(arr))