from collections import deque

def graph_hangout(graph: list[list[int]], node1: int, node2: int, node3: int)->int:
  def calc_distance(start: int):
    queue = deque()
    queue.append((start, 0)) # start_node, distance
    number_of_edges = {}

    while len(queue) > 0:
      node, distance = queue.popleft()
      if node in number_of_edges:
        number_of_edges[node] = min(number_of_edges[node], distance)
      else:
        number_of_edges[node] = distance

      for nei in graph[node]:
        if nei not in number_of_edges:
          queue.append((nei, distance+1))
        elif number_of_edges[nei] > distance + 1: 
          queue.append((nei, distance+1))

    return number_of_edges

  distances = {}
  for start in [node1, node2, node3]:
    distances[start] = calc_distance(start)
  
  min_total_number_of_edge = 10e12
  for node in range(len(graph)):
    total_number_of_edge = distances[node1][node] + distances[node2][node] + distances[node3][node]
    min_total_number_of_edge = min(min_total_number_of_edge, total_number_of_edge)
  
  return min_total_number_of_edge

if __name__ == "__main__":
  # Example1
  graph = [
    [1, 4],   # Node 0
    [0, 2],   # Node 1
    [1, 3],   # Node 2
    [2, 4],   # Node 3
    [0, 3]    # Node 4
  ]
  node1 = 0
  node2 = 2
  node3 = 4
  print(graph_hangout(graph, node1, node2, node3))

  # Example2
  graph = [
    [1, 2, 3],  # Node 0
    [0, 2, 3],  # Node 1
    [0, 1, 3],  # Node 2
    [0, 1, 2]   # Node 3
  ]
  node1 = 0
  node2 = 1
  node3 = 2
  print(graph_hangout(graph, node1, node2, node3))
