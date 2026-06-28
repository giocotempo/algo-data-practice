import heapq

class TopSongs:
  def __init__(self, k: int):
    self.k = k
    self.heap = []
    self.plays = {}

  def register_plays(self, title: str, plays: int):
    new_plays = plays
    if title in self.plays:
      new_plays = self.plays[title] + plays
      self.plays[title] = new_plays
    else:
      self.plays[title] = plays
    heapq.heappush(self.heap, (-new_plays, title))
  
  def top_k(self):
    top_songs = []
    while len(top_songs) < self.k:
      plays, title = heapq.heappop(self.heap)
      if self.plays[title] == -plays:
        top_songs.append(title)
    
    return top_songs

if __name__ == "__main__":
  s = TopSongs(3)
  s.register_plays("Boolean Rhapsody", 100)
  s.register_plays("Boolean Rhapsody", 193)  # Total 293
  s.register_plays("Coding In The Deep", 75)
  s.register_plays("Coding In The Deep", 75)  # Total 150
  s.register_plays("All About That Base Case", 200)
  s.register_plays("All About That Base Case", 90)  # Total 290
  s.register_plays("All About That Base Case", 1)   # Total 291
  s.register_plays("Here Comes The Bug", 223)
  s.register_plays("Oops! I Broke Prod Again", 274)
  s.register_plays("All the Single Brackets", 132)
  print(s.top_k())
