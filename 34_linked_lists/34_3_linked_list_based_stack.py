class Node:
  def __init__(self, val):
    self.val = val
    self.next = None

class SinglyLinkedList:
  def __init__(self):
    self.head = None
    self._size = 0
  
  def push_front(self, val):
    new_node = Node(val)
    new_node.next = self.head
    self.head = new_node
    self._size += 1
  
  def pop_front(self):
    if not self.head:
      return None
    
    val = self.head.val
    self.head = self.head.next
    self._size -= 1
    return val
  
  def peek(self):
    if not self.head:
      return None
    return self.head.val

class Stack:
  def __init__(self):
    self._stack = SinglyLinkedList()

  def push(self, val):
    self._stack.push_front(val)

  def pop(self):
    return self._stack.pop_front()

  def peek(self):
    return self._stack.peek()
  
  def size(self):
    return self._stack._size

  def empty(self):
    return self._stack._size == 0
  
if __name__ == "__main__":
  stack = Stack()
  stack.push(1)    # Stack is now: 1
  stack.push(2)    # Stack is now: 1->2
  stack.push(3)    # Stack is now: 1->2->3
  print(stack.peek())     # Returns 3
  print(stack.size())     # Returns 3
  print(stack.empty())    # Returns False
  stack.pop()      # Returns 3, stack is now: 2->1
  stack.pop()      # Returns 2, stack is now: 1
  stack.pop()      # Returns 1, stack is now empty
  print(stack.empty())    # Returns True


  stack = Stack()
  stack.pop()      # Returns None (empty stack)
  print(stack.peek())     # Returns None (empty stack)
  print(stack.size())     # Returns 0
  print(stack.empty())    # Returns True