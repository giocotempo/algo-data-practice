is_acyclic = True
def tree_check(graph: list)->bool:
  global is_acyclic
  start = -1
  for i, neis in enumerate(graph):
    if len(neis) == 1:
      start = i
      break

  if start == -1:
    return False
  
  predecessors = {}
  predecessors[start] = None
  visit = set()
  visit.add(start)

  # DFS
  dfs(graph, predecessors, visit, start)

  # Tree Check
  is_connected = len(visit) == len(graph)
  if is_connected and is_acyclic:
    return True
  else:
    return False

def dfs(graph: list, predecessors: dict, visit: set, node: int):
  global is_acyclic
  for nei in graph[node]:
    if nei not in visit:
      visit.add(nei)
      predecessors[nei] = node
      dfs(graph, predecessors, visit, nei)
    elif nei != predecessors[node]:
      is_acyclic = False

if __name__ == "__main__":
  # Example1
  graph = [
    [2],           # Node 0
    [2, 5],        # Node 1
    [0, 1, 3, 4],  # Node 2
    [2],           # Node 3
    [2],           # Node 4
    [1]            # Node 5
  ]
  print(tree_check(graph))

  # Example2
  graph = [
    [2],           # Node 0
    [5],           # Node 1
    [0, 3],        # Node 2
    [2],           # Node 3
    [],            # Node 4
    [1]            # Node 5
  ]
  print(tree_check(graph))

  # Example3
  graph = [
    [1],           # Node 0
    [0, 2, 5],     # Node 1
    [1, 3, 4],     # Node 2
    [2],           # Node 3
    [2, 5],        # Node 4
    [1, 4]         # Node 5
  ]
  print(tree_check(graph))