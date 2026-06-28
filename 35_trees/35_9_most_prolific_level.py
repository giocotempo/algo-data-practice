from collections import deque

class Node:
  def __init__(self):
    self.left = None
    self.right = None

def most_prolific_level(root: Node)->int:
  if root is None:
    return -1
  
  queue = deque()
  queue.append((root, 0)) # Node, depth

  cur = 0
  cur_level = 0

  n_nodes = []

  while len(queue) > 0:
    node, depth = queue.popleft()
    if depth > cur_level:
      n_nodes.append(cur)
      cur_level = depth
      cur = 1
  
    elif depth == cur_level:
      cur += 1

    if node.left:
      queue.append((node.left, depth+1))
    if node.right:
      queue.append((node.right, depth+1))
  n_nodes.append(cur)
  
  max_prolificness = -1
  max_level = None
  
  for i in range(len(n_nodes)-1):
    prolificness = n_nodes[i + 1] / n_nodes[i]
    if prolificness > max_prolificness:
      max_prolificness = prolificness
      max_level = i
  
  return max_level

if __name__ == "__main__":
  node1 = Node()
  node2 = Node()
  node3 = Node()
  node4 = Node()
  node5 = Node()
  node6 = Node()
  node7 = Node()

  node1.left = node2
  node2.left = node3
  node2.right = node4
  node3.left = node5
  node3.right = node6
  node4.right = node7

  print(most_prolific_level(node1))
  