import math

def topological_sort(graph: list[list[list[int]]])->list[int]:
  v = len(graph)
  in_degrees = [0] * v

  for node in range(v):
    for nbr, _ in graph[node]:
      in_degrees[nbr] += 1

  zero_degrees = []
  for node in range(v):
    if in_degrees[node] == 0:
      zero_degrees.append(node)

  topo_order = []
  while len(zero_degrees) > 0:
    node = zero_degrees.pop()
    topo_order.append(node)
    for nbr, _ in graph[node]:
      in_degrees[nbr] -= 1
      if in_degrees[nbr] == 0:
        zero_degrees.append(nbr)
  
  if len(topo_order) < v:
    return []
  
  return topo_order

def dag_longest_path(graph: list[list[list[int]]], start):
  topo_order = topological_sort(graph)
  distances = {start: 0}
  predecessors = {}
  for node in topo_order:
    if node not in distances: continue
    for nbr, weight in graph[node]:
      if nbr not in distances or distances[node] + weight > distances[nbr]:
        distances[nbr] = distances[node] + weight
  
  res = []
  for node in range(len(graph)):
    if node not in distances:
      res.append(-math.inf)
    else:
      res.append(distances[node])

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
  print(dag_longest_path(graph, start))