from collections import deque

def rgb_distances(screen: list[str])->list[list[int]]:
  if screen == []:
    return []
  h, w = len(screen), len(screen[0])

  def closest_pixel(r1: int, c1: int, target: str):
    visited = set()
    q = deque()
    q.append((r1, c1))
    while len(q) > 0:
      r2, c2 = q.popleft()
      if (r2, c2) not in visited:
        visited.add((r2, c2))
        if screen[r2][c2] == target:
          return r2, c2
        if r2 - 1 >= 0:
          q.append((r2 - 1, c2))
        if r2 + 1 <= h - 1:
          q.append((r2 + 1, c2))
        if c2 - 1 >= 0:
          q.append((r2, c2 - 1))
        if c2 + 1 <= w - 1:
          q.append((r2, c2 + 1))

  output = [[0 for _ in range(w)] for _ in range(h)]
  for r1 in range(h):
    for c1 in range(w):
      if screen[r1][c1] == "R":
        r2, c2 = closest_pixel(r1, c1, "G")
        output[r1][c1] = abs(r1-r2) + abs(c1-c2)
      elif screen[r1][c1] == "G":
        r2, c2 = closest_pixel(r1, c1, "B")
        output[r1][c1] = abs(r1-r2) + abs(c1-c2)
      elif screen[r1][c1] == "B":
        r2, c2 = closest_pixel(r1, c1, "R")
        output[r1][c1] = abs(r1-r2) + abs(c1-c2)

  return output

if __name__ == "__main__":
  # Example1
  screen = [
    "RRRGRB",
    "BGRGRR",
    "RRRGRR",
    "RGRRRR",
    "GBGRGG"
  ]
  print(rgb_distances(screen))

  # Example2
  screen = [
    "RGB"
  ]
  print(rgb_distances(screen))