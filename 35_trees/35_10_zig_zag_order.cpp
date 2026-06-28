#include <iostream>
#include <deque>
#include <vector>
#include <utility>

struct Node {
  int val;
  Node* left;
  Node* right;

  Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

std::vector<int> zig_zag_order(Node* root) {
  std::vector<int> output;
  std::deque<std::pair<Node*, int>> stack;
  std::deque<std::pair<Node*, int>> queue;
  queue.push_back(std::make_pair(root, 0));

  auto consume_queue = [&]() {
    while (queue.size() > 0) {
      std::pair<Node*, int> item = queue.front();
      queue.pop_front();
      Node* node = item.first;
      int level = item.second;

      if (!node) {
        continue;
      }

      output.push_back(node->val);
      if (level % 2 == 0) {
        if (node->left) {
          stack.push_front(std::make_pair(node->left, level+1));
        }
        if (node->right) {
          stack.push_front(std::make_pair(node->right, level+1));
        }
      } else {
        if (node->right) {
          stack.push_front(std::make_pair(node->right, level+1));
        }
        if (node->left) {
          stack.push_front(std::make_pair(node->left, level+1));
        }
      }
    }
  };

  auto load_queue = [&]() {
    while (stack.size() > 0) {
      std::pair<Node*, int> item = stack.front();
      stack.pop_front();
      Node* node = item.first;
      int level = item.second;

      if (node) {
        queue.push_back(std::make_pair(node, level));
      }
    }
  };

  while (queue.size() > 0) {
    consume_queue();
    load_queue();
  }

  return output;
}

int main() {
    Node* node1 = new Node(5);
    Node* node2 = new Node(9);
    Node* node3 = new Node(6);
    Node* node4 = new Node(8);
    Node* node5 = new Node(2);
    Node* node6 = new Node(2);
    Node* node7 = new Node(1);
    Node* node8 = new Node(3);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node5->right = node7;
    node6->right = node8;

    std::vector<int> result = zig_zag_order(node1);

    std::cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
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
    delete node8;

    return 0;
}
