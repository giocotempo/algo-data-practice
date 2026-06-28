from collections import deque

def days_until_all_infected(graph: list[list[int]], infected: list[int])->int:
  queue = deque()
  infected_map = {}
  # Init
  for node in infected:
    infected_map[node] = 0
    queue.append((node, 0)) # node, days

  while len(queue) > 0:
    node, days = queue.popleft()
    for nei in graph[node]:
      if nei not in infected_map:
        infected_map[nei] = days + 1
        queue.append((nei, days + 1))

  max_days = 0
  for days in infected_map.values():
    if days > max_days:
      max_days = days
  
  return max_days

if __name__ == "__main__":
  # Example1
  graph = [
    [1, 2],
    [0, 2],
    [0, 1, 3],
    [2]
  ]
  infected = [0]
  print(days_until_all_infected(graph, infected)) # Output: 2

  # Example2
  graph = [
    [1],
    [0, 2],
    [1, 3],
    [2, 4],
    [3]
  ]
  infected = [0, 4]
  print(days_until_all_infected(graph, infected)) # Output: 2

  # Example3
  graph = [
    [1, 2],
    [0, 3],
    [0, 3],
    [1, 2]
  ]
  infected = [0, 3]
  print(days_until_all_infected(graph, infected)) # Output: 1