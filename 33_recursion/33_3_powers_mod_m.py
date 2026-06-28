def powers_mod_m(a: int, p: int, m: int) -> int:
  if p == 0:
    return 1
  
  mod = a * powers_mod_m(a, p-1, m) % m
  return mod

if __name__ == "__main__":
  # Example1
  a = 2
  p = 5
  m = 100
  print(powers_mod_m(a, p, m))

  # Example2
  a = 2
  p = 5
  m = 30
  print(powers_mod_m(a, p, m))