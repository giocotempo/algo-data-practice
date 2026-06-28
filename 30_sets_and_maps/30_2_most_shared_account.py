def most_shared_account(connections: list) -> str:
  hashmap = {}
  max_freq = 0
  max_account = ""
  for ip, account in connections:
    if account in hashmap:
      hashmap[account] += 1
    else:
      hashmap[account] = 1

    if hashmap[account] > max_freq:
        max_freq = hashmap[account]
        max_account = account

  return max_account

if __name__ == "__main__":
  connections = [
    ("203.0.113.10", "mike"),
    ("208.51.100.25", "bob"),
    ("202.0.2.5", "mike"),
    ("203.0.113.15", "bob2"),
  ]
  print(most_shared_account(connections))