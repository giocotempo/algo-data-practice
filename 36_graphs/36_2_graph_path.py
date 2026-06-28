from collections import deque

def graph_path(graph: list, node1, node2)->list:
  predecessors = {}
  visited = set()
  dfs(graph, visited, predecessors, node1)
  if node2 in predecessors:
    d = deque([])
    d.appendleft(node2)
    dst = node2
    while dst != node1:
      d.appendleft(predecessors[dst])
      dst = predecessors[dst]
    return list(d)
  else:
    return []

def dfs(graph: list, visited: set, predecessors: dict, node: int):
  for nei in graph[node]:
    if nei not in visited:
      visited.add(nei)
      predecessors[nei] = node
      dfs(graph, visited, predecessors, nei)
  
if __name__ == "__main__":
  graph = [
    [1],
    [0, 2, 5, 4],
    [1, 4, 5],
    [],
    [5, 2, 1],
    [1, 2, 4]
  ]
  # Example1
  node1 = 0
  node2 = 4
  print(graph_path(graph, node1, node2))
  # Example2
  node1 = 0
  node2 = 3
  print(graph_path(graph, node1, node2))