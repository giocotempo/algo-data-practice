from collections import deque

class Node:
  def __init__(self, val):
    self.val = val
    self.left = None
    self.right = None

def left_view(root: Node)->list[int]:
  output = []
  q = deque()
  q.append((root, 0)) # (Node, depth)
  viewed = set()

  while len(q) > 0:
    node, depth = q.popleft()
    if depth not in viewed:
      output.append(node.val)
      viewed.add(depth)
    
    if node.left:
      q.append((node.left, depth+1))
    if node.right:
      q.append((node.right, depth+1))

  return output

if __name__ == "__main__":
  node1 = Node(5)
  node2 = Node(2)
  node3 = Node(9)
  node4 = Node(6)
  node5 = Node(9)
  node6 = Node(8)
  node7 = Node(1)

  node1.left = node2
  node1.right = node3
  node2.right = node4
  node3.left = node5
  node3.right = node6
  node5.right = node7

  print(left_view(node1))