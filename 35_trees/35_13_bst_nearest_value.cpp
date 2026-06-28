#include <iostream>
#include <cstdlib>
#include <algorithm>

class Node {
  public:
    int val;
    Node* left;
    Node* right;

  Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

int bst_nearest_value(Node* node, int target) {
  if (target == node->val) {
    return node->val;
  }

  Node* cur = node;
  int min_val = cur->val;
  int min_dis = std::abs(target - cur->val);

  while(cur) {
    int dis = std::abs(target - cur->val);
    if (dis < min_dis) {
      min_dis = dis;
      min_val = cur->val;
    } else if (dis == min_dis) {
      min_val = std::min(cur->val, min_val);
    } else {
      return min_val;
    }

    if (target > cur->val) {
      cur = cur->right;
    } else {
      cur = cur->left;
    }
  }

  return min_val;
}

int main() {
  Node* node1 = new Node(8);
  Node* node2 = new Node(6);
  Node* node3 = new Node(12);
  Node* node4 = new Node(5);
  Node* node5 = new Node(8);
  Node* node6 = new Node(10);
  Node* node7 = new Node(2);
  Node* node8 = new Node(6);
  Node* node9 = new Node(8);
  Node* node10 = new Node(8);
  Node* node11 = new Node(9);

  node1->left = node2;
  node1->right = node3;
  node2->left = node4;
  node2->right = node5;
  node3->left = node6;
  node4->left = node7;
  node4->right = node8;
  node5->left = node9;
  node5->right = node10;
  node6->left = node11;

  int target = 7;
  std::cout << bst_nearest_value(node1, target) << std::endl;

  // Clean up memory
  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
  delete node6;
  delete node7;
  delete node8;
  delete node9;
  delete node10;
  delete node11;

  return 0;
}
