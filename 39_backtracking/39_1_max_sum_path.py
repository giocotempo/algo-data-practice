def calc_max_sum_path(grid: list)->int:
  global max_sum_path
  init = (0, 0)
  dfs(grid, init, 0)
  return max_sum_path

def dfs(grid: list, pos: tuple, sum_path: int):
  global max_sum_path
  i = pos[0]
  j = pos[1]
  h = len(grid)
  w = len(grid[0])
  sum_path += grid[i][j]

  if i == h-1 and j == w-1 and sum_path > max_sum_path:
    max_sum_path = sum_path
  
  else:
    if i != h-1 and j != w-1:
      dfs(grid, (i+1, j), sum_path)
      dfs(grid, (i, j+1), sum_path)
    elif i == h-1 and j != w-1:
      dfs(grid, (i, j+1), sum_path)
    elif i != h-1 and j == w-1:
      dfs(grid, (i+1, j), sum_path)

if __name__ == "__main__":
  # Example1
  grid = [
    [1, 4, 3],
    [2, 7, 6],
    [5, 8, 9]
  ]
  max_sum_path = 0
  print(calc_max_sum_path(grid))
  # Example2
  grid = [[5]]
  max_sum_path = 0
  print(calc_max_sum_path(grid))
