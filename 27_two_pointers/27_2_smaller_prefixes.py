def smaller_prefixes(arr: list)->bool:
  n = len(arr)
  for k in range(1, n//2+1):
    sum_k = sum(arr[:k])
    sum_2k = sum(arr[:2*k])
    if sum_k >= sum_2k:
      return False
  
  return True

if __name__ == "__main__":
  arr = [1, 2, 2, -1]
  print(smaller_prefixes(arr))
  arr = [1, 2, -2, 1, 3, 5]
  print(smaller_prefixes(arr))
