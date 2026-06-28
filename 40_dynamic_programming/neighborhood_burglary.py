def neighborhood_burglary(houses: list[int])->int:
  dp = [0] * len(houses)
  dp[0] = houses[0]
  dp[1] = max(houses[0], houses[1])
  
  for i in range(2, len(houses)):
    dp[i] = max(dp[i-1], dp[i-2]+houses[i])

  return dp[-1]

if __name__ == "__main__":
  houses = [200, 300, 200, 50]
  print(neighborhood_burglary(houses))