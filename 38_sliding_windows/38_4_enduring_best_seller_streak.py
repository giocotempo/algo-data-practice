def enduring_best_seller_streak(best_seller: list, k: int)->bool:
  l, r = 0, 0
  cur = 0
  hashmap = {}
  while r < len(best_seller):
    if best_seller[r] not in hashmap:
      hashmap[best_seller[r]] = 0
    hashmap[best_seller[r]] += 1
    cur += 1
    if cur == k:
      if hashmap[best_seller[r]] == k:
        return True
      
      hashmap[best_seller[l]] -= 1
      l += 1
      cur -= 1
    
    r += 1

  return False

if __name__ == "__main__":
  best_seller = ["book3", "book1", "book3", "book3", "book2"]
  k = 3
  print(enduring_best_seller_streak(best_seller, k))
  best_seller = ["book3", "book1", "book3", "book3", "book2"]
  k = 2
  print(enduring_best_seller_streak(best_seller, k))