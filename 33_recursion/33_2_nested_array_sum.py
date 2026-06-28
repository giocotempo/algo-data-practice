def nested_array_sum(arr: list)->int:
  def calc_array_sum(nums: list):
    array_sum = 0
    for e in nums:
      if isinstance(e, list):
        array_sum += calc_array_sum(e)
      else:
        array_sum += e
    return array_sum

  return calc_array_sum(arr)

if __name__ == "__main__":
  arr = [1, [2, 3], [4, [5]], 6]
  print(nested_array_sum(arr))

  arr = [[[[1]], 2]]
  print(nested_array_sum(arr))

  arr = []
  print(nested_array_sum(arr))