def permutation_enumeration(arr: list[str])->list[list[str]]:
  output = []
  candidates = []
  used = set()
  back_track(arr, candidates, used, output)
  return output

def back_track(arr: list, candidates:list, used: set, output: list):
  if len(candidates) == len(arr):
    output.append(candidates[:])
    return
  
  for n in arr:
    if n not in used:
      used.add(n)
      candidates.append(n)

      back_track(arr, candidates, used, output)

      used.remove(n)
      candidates.pop()

if __name__ == "__main__":
  # Example1
  arr = ['x', 'y', 'z']
  print(permutation_enumeration(arr))
  # Example2
  arr = ['x']
  print(permutation_enumeration(arr))