from collections import deque

def compress_array_by_k(arr: list[int], k: int)->list[int]:
  stack = deque()

  for num in arr:
    stack.append(num)
    if can_compress(stack, k, num):
      compress(stack, k)
  
  return list(stack)

def can_compress(stack: deque, k: int, num: int)->bool:
  if len(stack) < k:
    return False

  tmp = deque()

  def restore():
    while len(tmp) > 0:
      stack.append(tmp.pop())

  for _ in range(k):
    val = stack.pop()
    tmp.append(val)
    if val != num:
      restore()
      return False
  
  restore()
  return True

def compress(stack: deque, k: int):
  compressed_val = 0
  for _ in range(k):
    compressed_val += stack.pop()
  stack.append(compressed_val)
  if can_compress(stack, k, compressed_val):
    compress(stack, k)

if __name__ == "__main__":
  # Example1
  arr = [1, 9, 9, 3, 3, 3, 4]
  k = 3
  print(compress_array_by_k(arr, k))

  # Example2
  arr = [8, 4, 2, 2]
  k = 2
  print(compress_array_by_k(arr, k))

  # Example3
  arr = [4, 4, 4, 4]
  k = 5
  print(compress_array_by_k(arr, k))