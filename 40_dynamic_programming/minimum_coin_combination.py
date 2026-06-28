def minimum_coin_combination(coins: list[int], target: int) -> int:
  dp = {0: -1}
  for coin in coins:
    dp[coin] = 1

  def count_minimum_combination(t: int):
    if t in dp:
      return
    
    min_numbers = -1
    dp[t] = min_numbers

    for i in range(1, t):
      count_minimum_combination(i)
      count_minimum_combination(t-i)
      if dp[i] != -1 and dp[t-i] != -1:
        if dp[t] == -1:
          dp[t] = dp[i] + dp[t-i]
        else:
          dp[t] = min(dp[t], dp[i] + dp[t-i])

  count_minimum_combination(target)
  return dp[target]


if __name__ == "__main__":
  # Example1
  coins = [1, 2, 3]
  target = 5
  print(minimum_coin_combination(coins, target))

  # Example2
  coins = [2, 4]
  target = 5
  print(minimum_coin_combination(coins, target))