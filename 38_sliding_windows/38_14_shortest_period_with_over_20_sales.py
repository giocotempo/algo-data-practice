import math

def shortest_period_with_over_20_sales(sales: list[int])->int:
  l, r = 0, 0
  cur_min = math.inf

  while r < len(sales):
    window = sum(sales[l:r+1])
    if window > 20 and r - l + 1 < cur_min:
      cur_min = r - l + 1
      l += 1
    else:
      r += 1

  return cur_min if cur_min != math.inf else -1
  

if __name__ == "__main__":
  # Example1
  sales = [5, 10, 15, 5, 10]
  print(shortest_period_with_over_20_sales(sales))

  # Example2
  sales = [5, 10, 4, 5, 10]
  print(shortest_period_with_over_20_sales(sales))

  # Example3
  sales = [5, 5, 5, 5]
  print(shortest_period_with_over_20_sales(sales))
