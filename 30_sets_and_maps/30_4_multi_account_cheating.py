def multi_account_cheating(users: list)->bool:
  hashset = set()
  for user, ips in users:
    for ip in ips:
      if ip not in hashset:
        hashset.add(ip)
      else:
        return True
  return False

if __name__ == "__main__":
  # Example
  users = [
    ("mike", ["203.0.3.10", "208.51.0.5", "52.0.2.5"]),
    ("bob", ["111.0.0.10", "222.0.0.5", "222.0.0.8"]),
    ("bob2", ["222.0.0.5", "222.0.0.8", "111.0.0.10"])
  ]
  print(multi_account_cheating(users))