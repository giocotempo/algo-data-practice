def topological_sort(graph: list[list[int]])->list[int]:
  v = len(graph)
  in_degrees = [0] * v
  for node in range(v):
    for nbr in graph[node]:
      in_degrees[nbr] += 1

  zero_degree = []
  for node in range(v):
    if in_degrees[node] == 0:
      zero_degree.append(node)

  topo_order = []
  while len(zero_degree) > 0:
    node = zero_degree.pop()
    topo_order.append(node)
    for nbr in graph[node]:
      in_degrees[nbr] -= 1
      if in_degrees[nbr] == 0:
        zero_degree.append(nbr)
    
  if len(topo_order) < v:
    return []

  return topo_order

def counting_paths(graph: list[list[int]], start: int)->list[int]:
  topo_order = topological_sort(graph)
  counts = {start: 1}
  for node in topo_order:
    if node not in counts: continue
    for nbr in graph[node]:
      if nbr not in counts:
        counts[nbr] = counts[node]
      else:
        counts[nbr] += counts[node]
  
  res = []

  for node in range(len(graph)):
    if node not in counts:
      res.append(0)
    else:
      res.append(counts[node])

  return res

if __name__== "__main__":
  # Example
  graph = [
    [1],
    [],
    [1],
    [4],
    [1, 2, 5],
    [2]
  ]
  start = 4
  print(counting_paths(graph, start))