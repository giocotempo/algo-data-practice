def knapsack(cap: int, weights: list[int], values: list[int])->int:
    n = len(weights)
    dp = [[0] * (cap + 1) for _ in range(n)]

    for c in range(weights[0], cap+1):
        dp[0][c] = values[0]
    
    for i in range(1, n):
        for j in range(cap+1):
            if j - weights[i] >= 0:
                dp[i][j] = max(dp[i-1][j-weights[i]] + values[i], dp[i-1][j])
            else:
                dp[i][j] = dp[i-1][j]
    
    print(dp)
    return dp[-1][-1]

if __name__ == "__main__":
    cap = 7
    weights = [5, 3, 4, 1]
    values = [70, 50, 40, 10]
    print(knapsack(cap, weights, values))