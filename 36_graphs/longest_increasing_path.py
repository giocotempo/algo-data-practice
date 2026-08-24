def longest_increasing_path(graph: list[list[int]])->int:
    visited = set()
    longest_paths = 0

    def dfs(i: int, j: int, path: int):
        nonlocal longest_paths

        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        if (i, j) in visited:
            return

        visited.add((i, j))

        for dir in dirs:
            new_i = i + dir[0]
            new_j = j + dir[1]
            if 0 <= new_i < len(graph) and 0 <= new_j < len(graph[0]) and graph[new_i][new_j] > graph[i][j]:
                if path + 1 > longest_paths:
                    longest_paths = path + 1
                dfs(new_i, new_j, path+1)

    for i in range(len(graph)):
        for j in range(len(graph[0])):
            if (i, i) not in visited:
                dfs(i, j, 1)

    return longest_paths

if __name__ == "__main__":
    graph = [
        [1, 5, 8],
        [3, 4, 4],
        [7, 9, 2]
    ]
    print(longest_increasing_path(graph))
