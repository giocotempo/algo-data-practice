class Node:
  def __init__(self, val):
    self.val = val
    self.left = None
    self.right = None

def aligned_chain(root: Node)->int:
  def dfs(node: Node, depth: int)->int:
    desc_chain_left = 0
    desc_chain_right = 0

    if node.left:
      desc_chain_left = dfs(node.left, depth+1)
    if node.right:
      desc_chain_right = dfs(node.right, depth+1)

    if node.val == depth:
      return max(desc_chain_left, desc_chain_right) + 1
    return max(desc_chain_left, desc_chain_right)

  return dfs(root, 0)


if __name__ == "__main__":
  # Example:
  #               7
  #              / \
  #             1   3
  #            / \   \
  #           2   8   2
  #          / \     / \
  #         4   3   3   3
  node0 = Node(7)
  node1 = Node(1)
  node2 = Node(3)
  node3 = Node(2)
  node4 = Node(8)
  node5 = Node(2)
  node6 = Node(4)
  node7 = Node(3)
  node8 = Node(3)
  node9 = Node(3)

  node0.left = node1
  node0.right = node2
  node1.left = node3
  node1.right = node4
  node2.right = node5
  node3.left = node6
  node3.right = node7
  node5.left = node8
  node5.right = node9

  print(aligned_chain(node0))