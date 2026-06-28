class Node:
  def __init__(self, v):
    self.val = v
    self.next = None
    self.prev = None

class DoublyLinkedList:
  def __init__(self):
    self.head = None
    self.tail = None
    self._size = 0

  def push_front(self, v: int):
    new_node = Node(v)
    if self._size == 0:
      self.tail = new_node
    else:
      tmp = self.head
      tmp.prev = new_node
      new_node.next = tmp
    self.head = new_node

    self._size += 1

  def pop_front(self)->int|None:
    if self._size == 0:
      return None
    else:
      val = self.head.val  
      tmp = self.head.next
      tmp.prev = None
      self.head = tmp

    self._size -= 1
    return val

  def push_back(self, v: int):
    new_node = Node(v)
    if self._size == 0:
      self.head = new_node
    else:
      tmp = self.tail
      tmp.next = new_node
      new_node.prev = tmp
    self.tail = new_node

    self._size += 1

  def pop_back(self)->int|None:
    if self._size == 0:
      return None
    else:
      val = self.tail.val
      tmp = self.tail.prev
      tmp.next = None
      self.tail = tmp

    self._size -= 1
    return val

  def size(self)->int:
    return self._size

  def contains(self, v: int)->Node|None:
    head = self.head
    while head:
      node = head
      if node.val == v:
        return node
      else:
        head = head.next
    return None

if __name__ == "__main__":
  list = DoublyLinkedList()
  list.push_front(1)  # List is now: 1
  list.push_front(2)  # List is now: 2<->1
  list.push_back(3)   # List is now: 2<->1<->3
  print(list.contains(2))    # Returns node with value 2
  print(list.contains(4))    # Returns None (value not found)
  print(list.size())         # Returns 3
  print(list.pop_front())    # Returns 2, list is now: 1<->3
  print(list.pop_back())     # Returns 3, list is now: 1

  list = DoublyLinkedList()
  print(list.pop_front())    # Returns None (empty list)
  print(list.pop_back())     # Returns None (empty list)
  print(list.size())         # Returns 0