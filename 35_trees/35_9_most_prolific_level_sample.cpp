#include <iostream>
#include <queue>
#include <vector>
#include <utility>

class Node {
public:
  Node* left;
  Node* right;

  Node() : left(nullptr), right(nullptr) {}
};

int most_prolific_level(Node* root) {
  if (root == nullptr) {
    return -1;
  }

  std::queue<std::pair<Node*, int>> queue;
  queue.push(std::make_pair(root, 0)); // Node, depth

  int cur = 0;
  int cur_level = 0;

  std::vector<int> n_nodes;

  while (!queue.empty()) {
    std::pair<Node*, int> front = queue.front();
    queue.pop();
    Node* node = front.first;
    int depth = front.second;

    if (depth > cur_level) {
      n_nodes.push_back(cur);
      cur_level = depth;
      cur = 1;
    }
    else if (depth == cur_level) {
      cur += 1;
    }

    if (node->left) {
      queue.push(std::make_pair(node->left, depth + 1));
    }
    if (node->right) {
      queue.push(std::make_pair(node->right, depth + 1));
    }
  }
  n_nodes.push_back(cur);

  double max_prolificness = -1.0;
  int max_level = -1;

  for (int i = 0; i < static_cast<int>(n_nodes.size()) - 1; i++) {
    double prolificness = static_cast<double>(n_nodes[i + 1]) / n_nodes[i];
    if (prolificness > max_prolificness) {
      max_prolificness = prolificness;
      max_level = i;
    }
  }

  return max_level;
}

int main() {
  Node* node1 = new Node();
  Node* node2 = new Node();
  Node* node3 = new Node();
  Node* node4 = new Node();
  Node* node5 = new Node();
  Node* node6 = new Node();
  Node* node7 = new Node();

  node1->left = node2;
  node2->left = node3;
  node2->right = node4;
  node3->left = node5;
  node3->right = node6;
  node4->right = node7;

  std::cout << most_prolific_level(node1) << std::endl;

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
