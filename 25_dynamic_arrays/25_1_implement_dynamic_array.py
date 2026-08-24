class DynamicArray:
    def __init__(self, size: int):
        self._extend_size = 10
        self._total_size = self._extend_size
        self._size = 0
        self._array = [None] * size

    def append(self, val: int):
        self._array[self._size] = val
        self._size += 1
        if self._size == self._total_size:
            self._array = self._array + [None] * self._extend_size
            self._total_size += self._extend_size

    def get(self, i: int):
        if i < 0 or i >= self._size:
            raise IndexError("out of range")

        return self._array[i]

    def set(self, i: int, val: int):
        if i < 0 or i >= self._size:
            raise IndexError("out of range")

        self._array[i] = val

    def size(self):
        return self._size

    def pop_back(self):
        if self._size == 0:
            raise ValueError("No value")

        self._array[self._size - 1] = None
        self._size -= 1

if __name__ == "__main__":
    # Example
    array = DynamicArray(10)
    for i in range(15):
        array.append(i)

    for i in range(array.size()):
        print(array.get(i))

    array.set(0, 100)

    array.pop_back()
    for i in range(array.size()):
        print(array.get(i))

