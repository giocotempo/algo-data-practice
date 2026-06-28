def spanning_tree(graph: list[list[int]])->list[list[int]]:
  if len(graph) <= 1:
    return []
  
  output = []
  visit = {0}

  def dfs(node: int):
    for nei in graph[node]:
      if nei not in visit:
        output.append([node, nei])
        visit.add(nei)
        dfs(nei)

  dfs(0)

  return output

if __name__ == "__main__":
  graph = [
    [1],           # Node 0
    [0, 2, 5],     # Node 1
    [1, 3, 4],     # Node 2
    [2],           # Node 3
    [2, 5],        # Node 4
    [1, 4]         # Node 5
  ]
  print(spanning_tree(graph))