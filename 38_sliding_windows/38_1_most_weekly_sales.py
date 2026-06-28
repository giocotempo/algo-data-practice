def most_weekly_days(sales: list) -> int:
  if len(sales) < 7:
    return 0

  max_sales = 0
  l, r = 0, 7
  while r <= len(sales):
    if sum(sales[l:r]) > max_sales:
      max_sales = sum(sales[l:r])
    l += 1
    r += 1

  return max_sales 

if __name__ == "__main__":
  # Example1
  sales = [0, 3, 7, 12, 10, 5, 0, 1, 0, 15, 12, 11, 1]
  print(most_weekly_days(sales))

  # Example2
  sales = [0, 3, 7, 12]
  print(most_weekly_days(sales))