def most_frequent_octet(ips: list) -> str:
  hashmap = {}
  for ip in ips:
    first_octet = ip.split(".")[0]
    if first_octet not in hashmap:
      hashmap[first_octet] = 0
    hashmap[first_octet] += 1
  
  max_octet = ""
  max_count = 0
  for octet, count in hashmap.items():
    if count > max_count:
      max_octet = octet
      max_count = count
  
  return max_octet

if __name__ == "__main__":
  ips = ["203.0.113.10", "208.51.100.5", "202.0.2.5", "203.0.113.5"]
  print(most_frequent_octet(ips))