def road_trip(times: list)->int:
  size = len(times)
  if size < 3:
    return 0
  dp = [0] * size
  dp[0] = times[0]
  dp[1] = times[1]
  dp[2] = times[2]
  
  for i in range(3, size):
    dp[i] = times[i] + min(dp[i-1], dp[i-2], dp[i-3])
  
  print(dp)
  return min(dp[size-1], dp[size-2], dp[size-3])

if __name__ == "__main__":
  # Example1
  times = [8, 1, 2, 3, 9, 6, 2, 4]
  print(road_trip(times))

  # Example2
  times = [8, 1, 2, 3, 9, 3, 2, 4]
  print(road_trip(times))

  # Example3
  times = [10, 10]
  print(road_trip(times))

  