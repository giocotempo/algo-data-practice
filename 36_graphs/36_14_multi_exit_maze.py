from collections import deque

def multi_exit_maze(maze: list[str])->list[list[int]]:
  dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
  
  def grid_bfs(i: int, j: int):
    queue = deque()
    queue.append((i, j, 0))
    while len(queue) > 0:
      r, c, dis = queue.popleft()
      for dir in dirs:
        new_r = r + dir[0]
        new_c = c + dir[1]
        if new_r < 0 or new_c < 0 or new_r > len(maze)-1 or new_c > len(maze[0])-1: continue
        if maze[new_r][new_c] == "O":
          res[i][j] = dis + 1
          return
        elif maze[new_r][new_c] == ".":
          queue.append((new_r, new_c, dis + 1))
  
  res = [[0] * len(maze[0]) for _ in range(len(maze))]

  for i in range(len(maze)):
    for j in range(len(maze[0])):
      if maze[i][j] == "O":
        res[i][j] = 0
      elif maze[i][j] == "X":
        res[i][j] = -1
      else:
        grid_bfs(i, j)
  
  return res

if __name__ == "__main__":
  # Example1
  maze = [
    "...X.O",
    "OX.X..",
    "...X..",
    ".X....",
    "XOX.XX"
  ]
  print(multi_exit_maze(maze))

  # Example2
  maze = [
    "...",
    ".O.",
    "..."
  ]
  print(multi_exit_maze(maze))