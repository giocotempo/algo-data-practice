def minivan_road_trip(times: list[int], k: int)->int:
  n = len(times)
  dp = [0] * n
  for i in range(k+1):
    dp[i] = times[i]

  for i in range(k+1, n):
    dp[i] = times[i] + min(dp[i-k-1:i])

  return min(dp[n-k:])

if __name__ == "__main__":
  # Example1
  times = [8, 1, 2, 3, 9, 6, 2, 4]
  k = 2
  print(minivan_road_trip(times, k))
  # Example2
  times = [8, 1, 2, 3, 9, 6, 2, 4]
  k = 3
  print(minivan_road_trip(times, k))