def climbing_stairs(n: int)->int:
  dp = [0] * n
  dp[0] = 1
  dp[1] = 2

  for i in range(2, n):
    dp[i] = dp[i-1] + dp[i-2]
  
  return dp[-1]

if __name__ == "__main__":
  n = 4
  print(climbing_stairs(n))