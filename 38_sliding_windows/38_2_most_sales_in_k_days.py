def most_sales_in_k_days(sales: list, k: int) -> int:
  l, r = 0, 0
  max_sales_index = None
  max_sales = 0
  while r <= len (sales):
    r += 1
    if r - l == k:
      if sum(sales[l:r]) > max_sales:
        max_sales = sum(sales[l:r])
        max_sales_index = l
      l += 1
  
  return max_sales_index


if __name__ == "__main__":
  sales = [8, 1, 3, 7]
  k = 2
  print(most_sales_in_k_days(sales, k))