def aligned_path():
  pass

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

  print(aligned_path(node0))
