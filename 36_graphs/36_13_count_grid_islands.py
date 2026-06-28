def count_grid_islands(grid: list[list[int]])->int:
  if len(grid) == 0 or len(grid[0]) == 0:
    return 0

  visited = set()
  dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
  count = 0

  def grid_dfs(r, c):
    for dir in dirs:
      new_r = r + dir[0]
      new_c = c + dir[1]
      if new_r < 0 or new_c < 0 or new_r > len(grid)-1 or new_c > len(grid[0])-1: continue

      if (new_r, new_c) not in visited:
        visited.add((new_r, new_c))
        if grid[new_r][new_c] == 1:
          grid_dfs(new_r, new_c)

  for r in range(len(grid)):
    for c in range(len(grid[0])):
      if (r, c) in visited: continue
      if grid[r][c] == 0:
        visited.add((r, c))
      else:
        visited.add((r, c))
        count += 1
        grid_dfs(r, c)

  return count

if __name__ == "__main__":
  # Example1 
  grid = [
    [0, 0, 1, 0],
    [1, 1, 0, 1],
    [0, 0, 1, 1]
  ]
  print(count_grid_islands(grid))

  # Example2
  grid = [[]]
  print(count_grid_islands(grid))