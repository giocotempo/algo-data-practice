def count_islands(matrix: list[list[int]])->int:
    res = 0
    visited = set()

    def dfs(i, j):
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        if (i, j) in visited:
            return
        if i < 0 or i > len(matrix) - 1 or j < 0 or j > len(matrix[0]) - 1:
            return
        
        visited.add((i, j))
        if matrix[i][j] == 1:
            for dir in dirs:
                dfs(i+dir[0], j+dir[1])

    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if matrix[i][j] == 1 and (i,j) not in visited:
                res += 1
            dfs(i, j)
    
    return res
                
if __name__ == "__main__":
    matrix = [
        [1, 1, 0, 0],
        [1, 1, 0, 0],
        [0, 0, 1, 1],
        [0, 0, 0, 1]
    ]
    print(count_islands(matrix))