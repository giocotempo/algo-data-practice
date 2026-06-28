#include <deque>
#include <vector>
#include <set>
#include <utility>
#include <iostream>

class Node {
public:
  int val;
  Node* left;
  Node* right;

  Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

std::vector<int> left_view(Node* root) {
  std::vector<int> output;
  std::deque<std::pair<Node*, int>> q;
  q.push_back(std::make_pair(root, 0)); // (Node, depth)
  std::set<int> viewed;

  while (!q.empty()) {
    std::pair<Node*, int> current = q.front();
    q.pop_front();
    Node* node = current.first;
    int depth = current.second;

    if (viewed.find(depth) == viewed.end()) {
      output.push_back(node->val);
      viewed.insert(depth);
    }

    if (node->left) {
      q.push_back(std::make_pair(node->left, depth + 1));
    }
    if (node->right) {
      q.push_back(std::make_pair(node->right, depth + 1));
    }
  }

  return output;
}

int main() {
  Node* node1 = new Node(5);
  Node* node2 = new Node(2);
  Node* node3 = new Node(9);
  Node* node4 = new Node(6);
  Node* node5 = new Node(9);
  Node* node6 = new Node(8);
  Node* node7 = new Node(1);

  node1->left = node2;
  node1->right = node3;
  node2->right = node4;
  node3->left = node5;
  node3->right = node6;
  node5->right = node7;

  std::vector<int> result = left_view(node1);
  std::cout << "[";
  for (size_t i = 0; i < result.size(); i++) {
    std::cout << result[i];
    if (i < result.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;

  // Clean up memory
  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
  delete node6;
  delete node7;

  return 0;
}
