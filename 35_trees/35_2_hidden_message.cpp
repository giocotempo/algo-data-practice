#include <iostream>
#include <string>
#include <vector>
#include <functional>

class Node {
  public:
    std::string val;
    Node* left;
    Node* right;

    Node(std::string v) : val(v), left(nullptr), right(nullptr) {}
};

std::string hidden_message(Node* root) {
  std::vector<char> output;

  std::function<void(Node*)> dfs = [&](Node* node) {
    if (!node) {
      return;
    }

    char first_chr = node->val[0];
    char second_chr = node->val[1];

    if (first_chr == 'b') {
      output.push_back(second_chr);
      dfs(node->left);
      dfs(node->right);
    }
    else if (first_chr == 'a') {
      dfs(node->left);
      dfs(node->right);
      output.push_back(second_chr);
    }
    else if (first_chr == 'i') {
      dfs(node->left);
      output.push_back(second_chr);
      dfs(node->right);
    }
  };

  dfs(root);

  return std::string(output.begin(), output.end());
}

int main() {
  Node* node1 = new Node("bn");
  Node* node2 = new Node("i_");
  Node* node3 = new Node("a!");
  Node* node4 = new Node("ae");
  Node* node5 = new Node("it");
  Node* node6 = new Node("br");
  Node* node7 = new Node("bi");
  Node* node8 = new Node("bc");
  Node* node9 = new Node("ay");

  node1->left = node2;
  node1->right = node3;
  node2->left = node4;
  node2->right = node5;
  node4->left = node7;
  node4->right = node8;
  node3->left = node6;
  node6->right = node9;

  std::cout << hidden_message(node1) << std::endl;

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

  return 0;
}
