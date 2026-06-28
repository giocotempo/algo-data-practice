from typing import Callable

def cctv_footage(is_stolen: Callable[[int], bool], t1: int, t2: int):
  while t2 - t1 > 1:
    m = (t1 + t2) // 2
    if is_stolen(m):
      t2 = m
    else:
      t1 = m

  return t2

if __name__ == "__main__":
  is_stolen = lambda t : t >= 5
  t1 = 0
  t2 = 10
  print(cctv_footage(is_stolen, t1, t2))
  
  is_stolen = lambda t : t >= 6
  t1 = 0
  t2 = 10
  print(cctv_footage(is_stolen, t1, t2))

  is_stolen = lambda t : t >= 3
  t1 = 0
  t2 = 10
  print(cctv_footage(is_stolen, t1, t2))
  
  