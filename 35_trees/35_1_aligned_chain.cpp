#include <iostream>
#include <algorithm>

struct Node {
  int val;
  Node* left;
  Node* right;

  Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

int dfs(Node* node, int depth) {
  int desc_chain_left = 0;
  int desc_chain_right = 0;

  if (node->left) {
    desc_chain_left = dfs(node->left, depth+1);
  }
  if (node->right) {
    desc_chain_right = dfs(node->right, depth+1);
  }

  if (node->val == depth) {
    return std::max(desc_chain_left, desc_chain_right) + 1;
  }
  return std::max(desc_chain_left, desc_chain_right);
}

int aligned_chain(Node* root) {
  return dfs(root, 0);
}

int main() {
  // Example:
  //               7
  //              / \
  //             1   3
  //            / \   \
  //           2   8   2
  //          / \     / \
  //         4   3   3   3
  Node* node0 = new Node(7);
  Node* node1 = new Node(1);
  Node* node2 = new Node(3);
  Node* node3 = new Node(2);
  Node* node4 = new Node(8);
  Node* node5 = new Node(2);
  Node* node6 = new Node(4);
  Node* node7 = new Node(3);
  Node* node8 = new Node(3);
  Node* node9 = new Node(3);

  node0->left = node1;
  node0->right = node2;
  node1->left = node3;
  node1->right = node4;
  node2->right = node5;
  node3->left = node6;
  node3->right = node7;
  node5->left = node8;
  node5->right = node9;

  std::cout << aligned_chain(node0) << std::endl;

  // Clean up memory
  delete node0;
  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
  delete node6;
  delete node7;
  delete node8;
  delete node9;

  return 0;
}