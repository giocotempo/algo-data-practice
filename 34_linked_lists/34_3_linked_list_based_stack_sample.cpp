#include <iostream>

class Node {
public:
  int val;
  Node* next;

  Node(int v) : val(v), next(nullptr) {}
};

class SinglyLinkedList {
private:
  Node* head;
  int _size;

public:
  SinglyLinkedList() : head(nullptr), _size(0) {}

  ~SinglyLinkedList() {
    while (head != nullptr) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }

  void push_front(int val) {
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
    _size++;
  }

  int pop_front() {
    if (head == nullptr) {
      return -1; // Sentinel value for empty
    }

    int val = head->val;
    Node* temp = head;
    head = head->next;
    delete temp;
    _size--;
    return val;
  }

  int peek() {
    if (head == nullptr) {
      return -1; // Sentinel value for empty
    }
    return head->val;
  }

  int size() {
    return _size;
  }

  bool empty() {
    return _size == 0;
  }
};

class Stack {
private:
  SinglyLinkedList _stack;

public:
  void push(int val) {
    _stack.push_front(val);
  }

  int pop() {
    return _stack.pop_front();
  }

  int peek() {
    return _stack.peek();
  }

  int size() {
    return _stack.size();
  }

  bool empty() {
    return _stack.empty();
  }
};

int main() {
  Stack stack;
  stack.push(1);    // Stack is now: 1
  stack.push(2);    // Stack is now: 1->2
  stack.push(3);    // Stack is now: 1->2->3
  std::cout << stack.peek() << std::endl;     // Returns 3
  std::cout << stack.size() << std::endl;     // Returns 3
  std::cout << (stack.empty() ? "True" : "False") << std::endl;    // Returns False
  stack.pop();      // Returns 3, stack is now: 2->1
  stack.pop();      // Returns 2, stack is now: 1
  stack.pop();      // Returns 1, stack is now empty
  std::cout << (stack.empty() ? "True" : "False") << std::endl;    // Returns True

  Stack stack2;
  stack2.pop();      // Returns -1 (empty stack)
  std::cout << stack2.peek() << std::endl;     // Returns -1 (empty stack)
  std::cout << stack2.size() << std::endl;     // Returns 0
  std::cout << (stack2.empty() ? "True" : "False") << std::endl;    // Returns True

  return 0;
}
