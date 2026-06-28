def account_sharing_detection(connections: list)->str:
  hashmap = set()
  for ip, user in connections:
    if user in hashmap:
      return ip
    else:
      hashmap.add(user)
  
  return ""

if __name__ == "__main__":
  # Example1
  connections = [
    ("203.0.113.10", "mike"),
    ("298.51.100.25", "bob"),
    ("292.0.2.5", "mike"),
    ("203.0.113.15", "bob2")
  ]
  print(account_sharing_detection(connections))

  # Example2
  connections = [
    ("111.0.0.0", "mike"),
    ("111.0.0.1", "mike"),
    ("111.0.0.2", "bob"),
    ("111.0.0.3", "bob")
  ]
  print(account_sharing_detection(connections))

  # Example3
  connections = [
    ("111.0.0.0", "mike"),
    ("111.0.0.1", "mike2"),
    ("111.0.0.2", "mike3"),
    ("111.0.0.3", "mike4")
  ]
  print(account_sharing_detection(connections))