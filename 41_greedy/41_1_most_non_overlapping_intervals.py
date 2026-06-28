import math

def most_non_overlapping_intervals(intervals: list)->int:
  intervals = sorted(intervals, key=lambda x:x[1])
  prev_end = -math.inf
  counter = 0
  
  for l, r in intervals:
    if l > prev_end:
      prev_end = r
      counter += 1
  return counter

if __name__ == "__main__":
  # Example1
  intervals = [[2, 3], [1, 4], [2, 3], [3, 6], [8, 9]]
  print(most_non_overlapping_intervals(intervals))
  # Example2
  intervals = [[1, 2], [2, 3], [3, 4]]
  print(most_non_overlapping_intervals(intervals))