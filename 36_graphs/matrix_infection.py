def matrix_infection(matrix: list[list[int]]):
    visited = set()
    seconds_to_infected = 0

    def dfs(i: int, j: int, seconds: int):
        nonlocal seconds_to_infected
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        if (i, j) in visited:
            return
        else:
            visited.add((i, j))

        if matrix[i][j] == 0:
            return
    
        if matrix[i][j] == 1:
            matrix[i][j] = 2
            seconds += 1
            if seconds > seconds_to_infected:
                seconds_to_infected = seconds

        for dir in dirs:
            new_i = i + dir[0]
            new_j = j + dir[1]
            if within_matrix(new_i, new_j, matrix):                
                dfs(new_i, new_j, seconds)

    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if matrix[i][j] == 2 and (i, j) not in visited:
                dfs(i, j, 0)

    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if matrix[i][j] == 1:
                return -1

    return seconds_to_infected

def within_matrix(i, j, matrix: list[list[int]]):
    if 0 <= i < len(matrix) and 0 <= j < len(matrix[0]):
        return True
    else:
        return False
    
if __name__ == "__main__":
    matrix = [[1, 1, 1, 0], [0, 0, 2, 1], [0, 1, 1, 0]]
    print(matrix_infection(matrix))