import math

def topological_sort(graph: list[list[list[int]]])->list[int]:
  v = len(graph)
  in_degrees = [0 for _ in range(v)]
  for node in range(v):
    for nbr, _ in graph[node]:
      in_degrees[nbr] += 1
  degree_zero = []
  for node in range(v):
    if in_degrees[node] == 0:
      degree_zero.append(node)
  
  topo_order = []
  while len(degree_zero) > 0:
    node = degree_zero.pop()
    topo_order.append(node)
    for nbr, _ in graph[node]:
      in_degrees[nbr] -= 1
      if in_degrees[nbr] == 0:
        degree_zero.append(nbr)
  
  if len(topo_order) < v:
    return []

  return topo_order

def distance(graph, start):
  topo_order = topological_sort(graph)
  distances = {start: 0}
  for node in topo_order:
    if node not in distances: continue
    for nbr, weight in graph[node]:
      if nbr not in distances or distances[node] + weight < distances[nbr]:
        distances[nbr] = distances[node] + weight
  
  res = []
  for i in range(len(graph)):
    if i in distances:
      res.append(distances[i])
    else:
      res.append(math.inf)
  return res

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
  print(distance(graph, start))