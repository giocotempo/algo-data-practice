def topological_sort(graph: list[list[list[int]]])->list[int]:
  # create degrees list
  v = len(graph)
  in_degrees = [0 for _ in range(v)]
  for node in range(v):
    for nbr, _ in graph[node]:
      in_degrees[nbr] += 1
  
  # create zero_degree list
  degree_zero = []
  for node in range(v):
    if in_degrees[node] == 0:
      degree_zero.append(node)

  # create topological sort
  topo_sort = []
  while len(degree_zero) > 0:
    node = degree_zero.pop()
    topo_sort.append(node)
    for nbr, _ in graph[node]:
      in_degrees[nbr] -= 1
      if in_degrees[nbr] == 0:
        degree_zero.append(nbr)
  if len(topo_sort) < v:
    return []
  
  return topo_sort

def shortest_path(graph: list[list[list[int]]], start: int, goal: int):
  topo_order = topological_sort(graph)
  distances = {start: 0}
  predecessors = {}
  for node in topo_order:
    if node not in distances: continue
    for nbr, weight in graph[node]:
      if nbr not in distances or distances[node] + weight < distances[nbr]:
        distances[nbr] = distances[node] + weight
        predecessors[nbr] = node
  
  if goal not in distances:
    return []
  
  path = [goal]
  while path[-1] != start:
    path.append(predecessors[path[-1]])

  path.reverse()
  
  return path

if __name__ == "__main__":
  # Example
  graph = [
    [[1, 10]],
    [],
    [[1, 10]],
    [[4, 12]],
    [[1, 11], [2, 21], [5, 14]],
    [[2, -30]]
  ]
  start = 4
  goal = 1
  print(shortest_path(graph, start, goal))