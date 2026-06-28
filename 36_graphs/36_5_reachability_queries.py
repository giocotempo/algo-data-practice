def reachability_queries(graph: list[list[int]], queries: list[int])->list[bool]:
  visited = set()
  node_to_cc = {}

  def dfs(graph: list[list[int]], cc_id: int, node: int):
    visited.add(node)
    node_to_cc[node] = cc_id
    for nei in graph[node]:
      if nei not in visited:
        dfs(graph, cc_id, nei)
  
  cc_id = 0
  for node in range(len(graph)):
    if node not in visited:
      dfs(graph, cc_id, node)
      cc_id += 1
  
  output = []
  for q1, q2 in queries:
    output.append(node_to_cc[q1] == node_to_cc[q2])

  return output

if __name__ == "__main__":
  graph = [
  [1],
  [0, 2, 5, 4],
  [1, 4, 5],
  [],
  [5, 2, 1],
  [1, 2, 4]
]
queries = [[0, 4], [0, 3]]
print(reachability_queries(graph, queries))