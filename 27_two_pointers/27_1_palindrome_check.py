def is_palindrome(s: str) -> bool:
  if len(s) == 0:
    return False

  l, r = 0, len(s) - 1
  while l < r:
    if s[l] != s[r]:
      return False
    l += 1
    r -= 1

  return True

if __name__ == "__main__":
  # Example1
  s = "level"
  print(is_palindrome(s))
  # Example2
  s = "naan"
  print(is_palindrome(s))
  # Example3
  s = "palindrome"
  print(is_palindrome(s))