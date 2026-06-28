import heapq

def most_listened_across_genre(genres: list[list[str, int]], k: int)->list[str]:
  most_listened = []
  for genre in genres:
    for title, play in genre:
      if len(most_listened) < k:
        heapq.heappush(most_listened, (play, title))
      elif most_listened[0][0] < play:
        heapq.heappop(most_listened)
        heapq.heappush(most_listened, (play, title))

  nlargest = heapq.nlargest(k, most_listened)

  return [title for _, title in nlargest]

if __name__ == "__main__":
  genres = [
    [ # Pop
      ["Coding In The Deep", 123],
      ["Someone Like GNU",    99],
      ["Hello World",         98]
    ],
    [ # Country
      ["Ring Of Firewalls",  217]
    ],
    [ # Rock
      ["Boolean Rhapsody",   184],
      ["Merge Together",     119],
      ["Hey Queue",          102]
    ]
  ]
  k = 5
  print(most_listened_across_genre(genres, k))