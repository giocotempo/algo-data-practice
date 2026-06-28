def topological_sort(graph: list[list[int]])->list[int]:
  V = len(graph)
  in_degrees = [0 for _ in range(V)]
  for node in range(V):
    for nbr in graph[node]:
      in_degrees[nbr] += 1
  
  degree_zero = []
  for node in range(V):
    if in_degrees[node] == 0:
      degree_zero.append(node)

  topo_order = []
  while degree_zero:
    node = degree_zero.pop()
    topo_order.append(node)
    for nbr in graph[node]:
      in_degrees[nbr] -= 1
      if in_degrees[nbr] == 0:
        degree_zero.append(nbr)
  if len(topo_order) < V:
    return []
    
  return topo_order

def parallel_compilation(seconds: list[int], imports: list[list[int]])->int:
  V = len(seconds)
  graph = [[] for _ in range(V)]
  for package in range(V):
    for imported_package in imports[package]:
      graph[imported_package].append(package)
  topo_order = topological_sort(graph)
  durations = {}
  for node in topo_order:
    if node not in durations:
      durations[node] = seconds[node]
    for nbr in graph[node]:
      if nbr not in durations:
        durations[nbr] = 0
      durations[nbr] = max(durations[nbr], durations[node] + seconds[nbr])
  return max(durations.values())

if __name__ == "__main__":
  # Example1
  seconds = [10, 20, 30]
  imports = [
    [],
    [],
    [0, 1]
  ]
  print(parallel_compilation(seconds, imports))
  # Example2
  seconds = [10, 20, 30]
  imports = [[], [], []]
  print(parallel_compilation(seconds, imports))
