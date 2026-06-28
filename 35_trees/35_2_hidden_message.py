class Node:
  def __init__(self, val):
    self.val = val
    self.left = None
    self.right = None
I
def hidden_message(root: Node):
  output = []

  def dfs(node: Node):
    if not node:
      return
    
    first_chr = node.val[0]
    second_chr = node.val[1]
    if  first_chr == "b":
      output.append(second_chr)
      dfs(node.left)
      dfs(node.right)

    elif first_chr == "a":
      dfs(node.left)
      dfs(node.right)
      output.append(second_chr)
    
    elif first_chr == "i":
      dfs(node.left)
      output.append(second_chr)
      dfs(node.right)

  dfs(root)

  return "".join(output)

if __name__ == "__main__":
  node1 = Node("bn")
  node2 = Node("i_")
  node3 = Node("a!")
  node4 = Node("ae")
  node5 = Node("it")
  node6 = Node("br")
  node7 = Node("bi")
  node8 = Node("bc")
  node9 = Node("ay")
  
  node1.left = node2
  node1.right = node3
  node2.left = node4
  node2.right = node5
  node4.left = node7
  node4.right = node8
  node3.left = node6
  node6.right = node9

  print(hidden_message(node1))