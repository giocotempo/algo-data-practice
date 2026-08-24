import heapq

class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self._size = 0

    def append(self, val):
        node = Node(val)
        if self._size == 0:
            self.head = node
            self.tail = node
        else:
            self.tail.next = node
            self.tail = node

        self._size += 1

    def pop_front(self):
        if self._size == 0:
            return None

        head = self.head
        self.head = self.head.next
        self._size -= 1
        return head

    def size(self):
        return self._size

def combined_sorted_linked_lists(slls: list[SinglyLinkedList])->SinglyLinkedList:
    heap = []
    for sll in slls:
        while sll.size() > 0:
            node = sll.pop_front()
            heapq.heappush(heap, node.val)

    sll = SinglyLinkedList()
    while len(heap) > 0:
        val = heapq.heappop(heap)
        sll.append(val)

    return sll

if __name__ == "__main__":
    sll1 = SinglyLinkedList()
    sll1.append(1)
    sll1.append(6)

    sll2 = SinglyLinkedList()
    sll2.append(1)
    sll2.append(4)
    sll2.append(6)

    sll3 = SinglyLinkedList()
    sll3.append(3)
    sll3.append(7)

    sll = combined_sorted_linked_lists([sll1, sll2, sll3])
    while sll.size() > 0:
        node = sll.pop_front()
        print(node.val)
