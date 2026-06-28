def magic_blackjack():
  # Rule1
  min_safe_value = 16
  max_safe_value = 21
  # Rule2
  max_deck_value = 10
  # Initialization
  dp = [0 for _ in range(min_safe_value + max_deck_value)]
  dp[0] = 0
  dp[1] = 1

  for i in range(2, min_safe_value + max_deck_value):
    if i <= 10:
      dp[i] = sum(dp) + 1
    if i == 11:
      dp[i] = sum(dp)
    if i >= 12:
      dp[i] = sum(dp[i-max_deck_value:min_safe_value]) 

  return sum(dp[max_safe_value+1:])

if __name__ == "__main__":
  print(magic_blackjack())