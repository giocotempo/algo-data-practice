def count_0_sum_paths(grid: list[list[int]])->int:
  dp = [[0] * len(grid[0]) for _ in range(len(grid))]
  
  for i in range(len(grid)):
    if grid[i][0] == 0:
      dp[i][0] = 1
    else:
      dp[i:][0] = 0

  for j in range(len(grid[0])):
    if grid[0][j] == 0:
      dp[0][j] = 1
    else:
      dp[0][j] = 0
  
  for i in range(1, len(grid)):
    for j in range(1, len(grid[0])):
      dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i][j-1]
  
  return dp[-1][-1]

if __name__ == "__main__":
  # Example1
  grid = [[0, 1, 1], [0, 0, 0], [1, 0, 0]]
  print(count_0_sum_paths(grid))
  # Example2
  grid = [[1]]
  print(count_0_sum_paths(grid))