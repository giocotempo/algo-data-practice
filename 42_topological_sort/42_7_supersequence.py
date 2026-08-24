def construct_graph(arr: list[str])->dict[str, list[str]]:
    graph = {}
    for s in arr:
        n = len(s)
        for i in range(n):
            if s[i] not in graph:
                graph[s[i]] = []

            if i < n - 1:
                graph[s[i]].append(s[i+1])

    return graph

def topological_sort(graph: dict[str, list[str]])->list[str]:
    in_degrees = {}
    for key in graph.keys():
        in_degrees[key] = 0
    
    for node, nbrs in graph.items():
        for nbr in nbrs:
            in_degrees[nbr] += 1
    
    zero_degrees = []
    for node, in_degree in in_degrees.items():
        if in_degree == 0:
            zero_degrees.append(node)

    topo_order = []
    while len(zero_degrees) > 0:
        node = zero_degrees.pop()
        topo_order.append(node)

        for nbr in graph[node]:
            in_degrees[nbr] -= 1
            if in_degrees[nbr] == 0:
                zero_degrees.append(nbr)
    
    return topo_order


def supersequence(arr: list[str])->bool:
    graph = construct_graph(arr)
    topo_order = topological_sort(graph)
    return len(topo_order) == len(graph)
    

if __name__ == "__main__":
    # Example1
    arr = ["abc", "bde", "df", "cfe"]
    print(supersequence(arr))

    # Example2
    arr = ["ab", "ba"]
    print(supersequence(arr))
    
    # Example3
    arr = ["aa"]
    print(supersequence(arr))