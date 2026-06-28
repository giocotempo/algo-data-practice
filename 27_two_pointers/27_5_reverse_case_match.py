def reverse_case_match(s: str)->bool:
  l, r = 0, len(s) - 1
  lower_letters = []
  upper_letters = []

  while l < len(s):
    if s[l].islower():
      lower_letters.append(s[l])
    if s[r].isupper():
      upper_letters.append(s[r].lower())

    l += 1
    r -= 1

  if "".join(lower_letters) == "".join(upper_letters):
    return True
  
  return False


if __name__ == "__main__":
  s = "haDrRAHd"
  print(reverse_case_match(s))
  s = "haHrARDd"
  print(reverse_case_match(s))