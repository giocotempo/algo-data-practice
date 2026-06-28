import heapq

class TopSongs:
  def __init__(self, k):
    self.k = k
    self.heap = []
  
  def register_plays(self, title, plays):
    heapq.heappush(self.heap, (plays, title))

  def top_k(self):
    top_k_obj = heapq.nlargest(self.k, self.heap)
    return [title for _, title in top_k_obj]

if __name__ == "__main__":
  s = TopSongs(3)
  s.register_plays("Boolean Rhapsody", 193)
  s.register_plays("Coding In The Deep", 146)
  print(s.top_k())
  s.register_plays("All About That Base Case", 291)
  s.register_plays("Here Comes The Bug", 223)
  s.register_plays("Oops! I Broke Prod Again", 274)
  s.register_plays("All the Single Brackets", 132)
  print(s.top_k())