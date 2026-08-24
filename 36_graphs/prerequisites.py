def determine_prerequisites(n: int, prerequisites: list[list[int]])->bool:
    graph = make_adjacent_list(n, prerequisites)
    topo_order = topological_sort(graph)
    return len(topo_order) == n

# peel-it-off
def topological_sort(graph: list[list[int]])->list[int]:
    in_degrees = {}
    for i in range(len(graph)):
        in_degrees[i] = 0

    for i in range(len(graph)):
        for nbr in graph[i]:
            in_degrees[nbr] += 1

    zero_degree = []
    for i in range(len(graph)):
        if in_degrees[i] == 0:
            zero_degree.append(i)

    topo_order = []
    while len(zero_degree) > 0:
        node = zero_degree.pop()
        topo_order.append(node)

        for nbr in graph[node]:
            in_degrees[nbr] -= 1
            if in_degrees[nbr] == 0:
                zero_degree.append(nbr)

    return topo_order

def make_adjacent_list(n: int, prerequisites: list[list[int]])->list[list[int]]:
    graph = [[] for _ in range(n)]
    for p in prerequisites:
        start = p[0]
        end = p[1]
        graph[start].append(end)

    return graph

if __name__ == "__main__":
    # Example1
    n = 3
    prerequisites = [[0, 1], [1, 2], [2, 1]]
    print(determine_prerequisites(n, prerequisites))
    # Example2
    n = 5
    prerequisites = [[0, 1], [1, 2], [2, 4], [4, 3]]
    print(determine_prerequisites(n, prerequisites))