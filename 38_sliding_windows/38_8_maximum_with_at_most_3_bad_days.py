from collections import deque

def maximum_with_at_most_3_bad_days(sales: list[int])->int:
  if len(sales) <= 3:
    return len(sales)

  l, r = 0, 1
  maximum = 0
  bad_day_pointers = deque()
  if sales[0] < 10:
    bad_days = 1
    bad_day_pointers.append(0)
  else:
    bad_days = 0

  while r < len(sales):
    if sales[r] < 10:
      bad_days += 1
      bad_day_pointers.append(r)
    
    if bad_days > 3:
      bad_day_left = bad_day_pointers.popleft()
      if sales[bad_day_left] < 10:
        bad_days -= 1
      l = bad_day_left + 1
    elif len(sales[l:r+1]) > maximum:
      maximum = len(sales[l:r+1])

    r += 1

  return maximum

if __name__ == "__main__":
  sales = [0, 14, 7, 9, 0, 20, 10, 0, 10]
  print(maximum_with_at_most_3_bad_days(sales))