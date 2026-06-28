def palindrome_sentence(s: str)->bool:
  if len(s) <= 1:
    return True
  excluded = [".", ",", " ", "?", "!", "'"]
  l, r = 0, len(s)-1
  while l < r:
    left = s[l]
    right = s[r]
    if left in excluded:
      l += 1
    elif right in excluded:
      r -= 1
    elif left.lower() == right.lower():
      l += 1
      r -= 1
    else:
      return False

  return True
 
if __name__ == "__main__":
  s = "Bob wondered, 'Now, Bob?'"
  print(palindrome_sentence(s))