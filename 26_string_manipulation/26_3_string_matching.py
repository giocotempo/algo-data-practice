def index_of(s: str, t: str)->int:
  i = 0
  while i < len(s) - len(t):
    if s[i:i+len(t)] == t:
      return i
    else:
      i += 1
  
  return -1

if __name__ == "__main__":
  s = "jjagjfahudgnk"
  t = "fah"
  print(index_of(s, t))