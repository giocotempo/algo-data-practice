class Node:
  def __init__(self, val):
    self.val = val
    self.left = None
    self.right = None

def bst_nearest_value(node: Node, target: int)->int:
  if target == node.val:
    return node.val
  
  cur = node
  min_val = cur.val
  min_dis = abs(target - cur.val)

  while cur:
    dis = abs(target - cur.val)
    if dis < min_dis:
      min_dis = dis
      min_val = cur.val
    elif dis == min_dis:
      min_val = min(cur.val, min_val)
    else:
      return min_val
    
    if target > cur.val:
      cur = cur.right
    else:
      cur = cur.left
  
  return min_val

if __name__ == "__main__":
  node1 = Node(8)
  node2 = Node(6)
  node3 = Node(12)
  node4 = Node(5)
  node5 = Node(8)
  node6 = Node(10)
  node7 = Node(2)
  node8 = Node(6)
  node9 = Node(8)
  node10 = Node(8)
  node11 = Node(9)

  node1.left = node2
  node1.right = node3
  node2.left = node4
  node2.right = node5
  node3.left = node6
  node4.left = node7
  node4.right = node8
  node5.left = node9
  node5.right = node10
  node6.left = node11

  target = 7
  print(bst_nearest_value(node1, target))