class Node:
  def __init__(self, val: int):
    self.val = val
    self.next = None

class SinglyLinkedList:
  def __init__(self):
    self.head = None
    self._size = 0
  
  def push_front(self, v: int):
    new_node = Node(v)

    if self._size == 0:
      self.head = new_node
      self._size += 1
      return

    new_node.next = self.head
    self.head = new_node
    self._size += 1

  def pop_front(self)->int:

    if self.size == 0:
      raise Exception("Error popping from front")
    
    popped_node = self.head
    self.head = self.head.next
    self._size -= 1
    return popped_node.val

  def push_back(self, v: int):
    new_node = Node(v)

    if self._size == 0:
      self.head = new_node
      self._size += 1
      return
    
    head = self.head
    while head.next:
      head = head.next

    head.next = new_node
    self._size += 1

  def pop_back(self)->int:
    if self._size == 0:
      raise Exception("Error popping from front")

    if self._size == 1:
      popped_node = self.head
      self.head = None
      self._size -= 1
      return popped_node.val
    
    head = self.head
    while head.next.next:
      head = head.next
    
    popped_node = head.next
    head.next = None
    self._size -= 1
    return popped_node.val

  def size(self)->int:
    return self._size
    
  def contains(self, v: int)->Node:
    if self.size == 0:
      return None

    head = self.head
    while head:
      if head.val == v:
        return head
      head = head.next
    
    return None

  def print(self):
    if self._size == 0:
      print("No node exist")

    print(f"""Total: {self._size} Nodes""")
    output = []
    head = self.head
    while head:
      output.append(f"""{head.val}->""")
      head = head.next

    print("".join(output))


if __name__ == "__main__":
  sll = SinglyLinkedList()
  sll.push_front(1)
  sll.push_front(2)
  sll.pop_back()
  sll.pop_front()
  sll.print()
  # No Nodes

  sll.push_back(1)
  sll.push_back(2)
  sll.push_back(3)
  print(sll.contains(2).val)
  sll.print()
  # 1->2->3->
  