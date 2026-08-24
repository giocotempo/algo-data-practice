import heapq

class Median:
    def __init__(self):
        self.min_half = []
        self.max_half = []

    def add(self, num: int):
        if self.min_half == []:
            heapq.heappush(self.min_half, -num)
            return
        
        if num <= -self.min_half[0]:
            if len(self.min_half) > len(self.max_half):
                tmp = heapq.heappop(self.min_half)
                heapq.heappush(self.max_half, -tmp)
            heapq.heappush(self.min_half, -num)
        else:
            if len(self.min_half) < len(self.max_half):
                tmp = heapq.heappop(self.max_half)
                heapq.heappush(self.min_half, -tmp)
            heapq.heappush(self.max_half, num)

    def get_median(self)->int:
        if len(self.min_half) == len(self.max_half):
            return (-self.min_half[0] + self.max_half[0]) / 2
        elif len(self.min_half) > len(self.max_half):
            return -self.min_half[0]
        else:
            return self.max_half[0]


if __name__ == "__main__":
    m = Median()
    m.add(3)
    m.add(6)
    print(m.get_median())
    m.add(1)
    print(m.get_median())
    m.add(2)
    print(m.get_median())
    m.add(4)
    print(m.get_median())
    m.add(7)
    print(m.get_median())