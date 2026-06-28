def channel_views(views: list, periods: list)->list:
  prefix_sums = []
  output = []
  previous_val = 0
  for view in views:
    previous_val += view
    prefix_sums.append(previous_val)
  
  for period in periods:
    start = period[0]
    end = period[1]
    if start == 0:
      output.append(prefix_sums[end])
    else:
      output.append(prefix_sums[end] - prefix_sums[start-1])
  
  return output

if __name__ == "__main__":
  views = [3, 5, 4, 8, 7, 2, 5, 3, 2, 3]
  periods = [[0, 1], [0, 5], [5, 8], [3, 3]]
  print(channel_views(views, periods))