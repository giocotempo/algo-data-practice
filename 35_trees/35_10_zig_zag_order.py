from collections import deque

class Node:
  def __init__(self, val):
    self.val = val
    self.left = None
    self.right = None

def zig_zag_order(root: Node)->list[int]:
  output = []
  stack = deque()
  queue = deque()
  queue.append((root, 0)) # node, level

  def consume_queue():
    while len(queue) > 0:
      node, level = queue.popleft()
      if not node:
        continue

      output.append(node.val)
      if level % 2 == 0:
        if node.left:
          stack.appendleft((node.left, level+1))
        if node.right:
          stack.appendleft((node.right, level+1))
      else:
        if node.right:
          stack.appendleft((node.right, level+1))
        if node.left:
          stack.appendleft((node.left, level+1))
        

  def load_queue():
    while len(stack) > 0:
      node, level = stack.popleft()
      if node:
        queue.append((node, level))

  while len(queue) > 0:
    consume_queue()
    load_queue()

  return output

if __name__ == "__main__":
  node1 = Node(5)
  node2 = Node(9)
  node3 = Node(6)
  node4 = Node(8)
  node5 = Node(2)
  node6 = Node(2)
  node7 = Node(1)
  node8 = Node(3)

  node1.left = node2
  node1.right = node3
  node2.left = node4
  node2.right = node5
  node3.left = node6
  node5.right = node7
  node6.right = node8

  print(zig_zag_order(node1))
