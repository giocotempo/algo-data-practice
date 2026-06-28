import heapq

def k_most_played(songs: list[list[str, int]], k: int) -> list[str]:
  k_most_played_songs = heapq.nlargest(k, songs, key=lambda x: x[1])
  return [title for title, _ in k_most_played_songs]

if __name__ == "__main__":
  # Example
  songs = [
    ["All the Single Brackets", 132],
    ["Oops! I Broke Prod Again", 274],
    ["Coding In The Deep", 146],
    ["Boolean Rhapsody", 193],
    ["Here Comes The Bug", 291],
    ["All About That Base Case", 291]
  ]
  k = 3
  print(k_most_played(songs, k))