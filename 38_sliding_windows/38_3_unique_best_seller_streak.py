def unique_best_seller_streak(best_seller: list, k: int)->bool:
  l, r = 0, 0
  window_counts = {}
  while r < len(best_seller):
    if not best_seller[r] in window_counts:
      window_counts[best_seller[r]] = 0
    window_counts[best_seller[r]] += 1
    r += 1
    if r - l == k:
      if len(window_counts) == k:
        return True
      window_counts[best_seller[l]] -= 1
      if window_counts[best_seller[l]] == 0:
        del window_counts[best_seller[l]]
      l += 1
  return False

if __name__ == "__main__":
  best_seller = ["book3", "book1", "book3", "book3", "book2", "book3", "book4", "book3"]
  k = 3
  print(unique_best_seller_streak(best_seller, k))