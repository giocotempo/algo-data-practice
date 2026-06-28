def split(s: str, c: str) -> list:
  output = []
  acc = []
  for el in s:
    if el == c:
      output.append("".join(acc))
      acc = []
    else:
      acc.append(el)

  output.append("".join(acc))
  
  return output

if __name__ == "__main__":
  # Example1
  s = "split by space" 
  c = " "
  print(split(s, c))
  # Example2
  s = "beekeeper needed"
  c = "e"
  print(split(s, c))
  # Example3
  s = "/home/./..//Documents/"
  c = "/"
  print(split(s, c))