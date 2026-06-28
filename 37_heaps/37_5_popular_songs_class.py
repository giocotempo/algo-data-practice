import statistics

class PopularSongs:
  def __init__(self):
    self.memo = {}
    self.plays_arr = []

  def register_plays(self, title: str, plays: int):
    self.memo[title] = plays
    self.plays_arr.append(plays)

  def is_popular(self, title: str):
    if statistics.median(self.plays_arr) < self.memo[title]:
      return True
    else:
      return False

if __name__ == "__main__":
  p = PopularSongs()
  p.register_plays("Boolean Rhapsody", 193)
  print(p.is_popular("Boolean Rhapsody"))
  p.register_plays("Coding In The Deep", 140)
  p.register_plays("All the Single Brackets", 132)
  print(p.is_popular("Boolean Rhapsody"))
  print(p.is_popular("Coding In The Deep"))
  print(p.is_popular("All the Single Brackets"))
  p.register_plays("All About That Base Case", 291)
  p.register_plays("Oops! I Broke Prod Again", 274)
  p.register_plays("Here Comes The Bug", 223)
  print(p.is_popular("Boolean Rhapsody"))
  print(p.is_popular("Here Comes The Bug"))