def longest_good_day_streak(sales: list[int])->int:
  l, r = 0, 0
  longest_days = 0
  while r < len(sales):
    if sales[r] >= 10:
      if r - l + 1 > longest_days:
        longest_days = r - l + 1
      r += 1
    else:
      r += 1
      l = r

  return longest_days

I