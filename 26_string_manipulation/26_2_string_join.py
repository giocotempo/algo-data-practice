def join(arr: list, s: str) -> str:
  if len(arr) == 0:
    return ""
  if len(arr) == 1:
    return arr[0]

  joined_arr = []

  for i in range(len(arr)):
    joined_arr.append(arr[i])
    if i < len(arr)-1:
      joined_arr.append(s)

  return "".join(joined_arr)  

if __name__ == "__main__":
  # Example1
  arr = ["join", "by", "space"] 
  s = " "
  print(join(arr, s))

  # Example2
  arr = ["b", "", "k", "", "p", "r n", "", "d", "d!!"]
  s = "ee"
  print(join(arr, s))