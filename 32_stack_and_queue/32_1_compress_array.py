from collections import deque

def compress_array(arr: list[int])->list[int]:
  stack = deque()
  def add_stack(num: int):
    if len(stack) == 0:
      stack.append(num)
    elif stack[-1] == num:
      stack.pop()
      add_stack(2 * num)
    else:
      stack.append(num)

  for num in arr:
    add_stack(num)

  return list(stack)

if __name__ == "__main__":
  # Example1
  arr = [8, 4, 2, 2, 2, 4]
  print(compress_array(arr))
  # Example2
  arr = [4, 4, 4, 4]
  print(compress_array(arr))
  # Example3
  arr = [1, 2, 3, 4]
  print(compress_array(arr))