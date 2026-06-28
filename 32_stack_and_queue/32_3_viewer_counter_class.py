from collections import deque

class ViewerCounter:
  def __init__(self, window):
    self.window = window
    self.counter = {"guest": deque(), "follower": deque(), "subscriber": deque()}

  def join(self, t: int, v: str):
    self.counter[v].append(t)

  def get_viewers(self, t: int, v: str)->int:
    l = t - self.window
    r = t
    new_queue = deque()
    result = 0

    while len(self.counter[v]) > 0:
      t = self.counter[v].popleft()
      if l <= t <= r:
        result += 1

      if l < t:
        new_queue.append(t)
    
    self.counter[v] = new_queue
    return result

if __name__ == "__main__":
  counter = ViewerCounter(10)
  counter.join(1, "subscriber")
  counter.join(1, "guest")
  counter.join(2, "follower")
  counter.join(2, "follower")
  counter.join(2, "follower")
  counter.join(3, "follower")
  print(counter.get_viewers(10, "subscriber"))  # Returns 1
  print(counter.get_viewers(10, "guest"))       # Returns 1
  print(counter.get_viewers(10, "follower"))    # Returns 4
  print(counter.get_viewers(13, "follower"))    # Returns 1