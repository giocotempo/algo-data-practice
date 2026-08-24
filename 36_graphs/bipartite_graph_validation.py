def bipartite_graph_validation(graph: list[list[int]])->bool:
    visited = {}
    conflict = 0

    def dfs(node: int, color: int):
        nonlocal conflict 

        if node in visited:
            if visited[node] != color:
                conflict += 1
            return
                
        visited[node] = color

        for nbr in graph[node]:
            dfs(nbr, -color)

    dfs(0, 1)
    return conflict == 0

if __name__ == "__main__":
    # Example1
    graph = [
        [1, 4],
        [0, 2],
        [1],
        [4],
        [0, 3]
    ]
    print(bipartite_graph_validation(graph))
    # Example2
    graph = [
        [1, 2, 4],
        [0, 2],
        [0, 1],
        [4],
        [0, 3]
    ]
    print(bipartite_graph_validation(graph))