from collections import deque

def shortest_path_queries(graph: list[list[int]], start: int, queries: list[int])->list[list[int]]:
  output = []
  queue = deque()
  queue.append((None, start))
  shortest_paths = {}

  while len(queue) > 0:
    prev, node = queue.popleft()

    if prev is None:
      shortest_paths[node] = [start]
      for nei in graph[node]:
          queue.append((node, nei))
    else:
      if node not in shortest_paths:
        shortest_path = shortest_paths[prev][:]
        shortest_path.append(node)
        shortest_paths[node] = shortest_path
        for nei in graph[node]:
          queue.append((node, nei))

  for query in queries:
    if query not in shortest_paths:
      output.append([])
    else:
      output.append(shortest_paths[query])

  return output

if __name__ == "__main__":
  # Example1
  graph = [
    [1],           # Node 0
    [0, 2, 5, 4],  # Node 1
    [1, 4, 5],     # Node 2
    [],            # Node 3
    [5, 2, 1],     # Node 4
    [1, 2, 4]      # Node 5
  ]
  start = 0
  queries = [1, 0, 3, 4]
  print(shortest_path_queries(graph, start, queries))

  # Example2
  graph = [
    [1],           # Node 0
    [0, 2],        # Node 1
    [1]            # Node 2
  ]
  start = 0
  queries = [1, 2]
  print(shortest_path_queries(graph, start, queries))

  # Example3
  graph = [
    [1],           # Node 0
    [0],           # Node 1
    [3],           # Node 2
    [2]            # Node 3
  ]
  start = 0
  queries = [1, 2, 3]
  print(shortest_path_queries(graph, start, queries))