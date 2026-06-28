def restaurant_ratings(ratings: list)->int:
  dp = [0] * len(ratings)
  dp[0] = ratings[0]
  dp[1] = max(dp[0], ratings[1])

  for i in range(2, len(ratings)):
    dp[i] = max(dp[i-2] + ratings[i], dp[i-1])

  return dp[-1]

if __name__ == "__main__":
  # Example1
  ratings = [8, 1, 3, 9, 5, 2, 1]
  print(restaurant_ratings(ratings))
  # Example2
  ratings = [8, 1, 3, 7, 5, 2, 4]
  print(restaurant_ratings(ratings))
