#include <iostream>
#include <stdexcept>
#include <string>

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

  void push_front(int v) {
    Node* new_node = new Node(v);

    if (_size == 0) {
      head = new_node;
      _size++;
      return;
    }

    new_node->next = head;
    head = new_node;
    _size++;
  }

  int pop_front() {
    if (_size == 0) {
      throw std::runtime_error("Error popping from front");
    }

    Node* popped_node = head;
    head = head->next;
    _size--;
    int val = popped_node->val;
    delete popped_node;
    return val;
  }

  void push_back(int v) {
    Node* new_node = new Node(v);

    if (_size == 0) {
      head = new_node;
      _size++;
      return;
    }

    Node* cur = head;
    while (cur->next) {
      cur = cur->next;
    }

    cur->next = new_node;
    _size++;
  }

  int pop_back() {
    if (_size == 0) {
      throw std::runtime_error("Error popping from front");
    }

    if (_size == 1) {
      Node* popped_node = head;
      head = nullptr;
      _size--;
      int val = popped_node->val;
      delete popped_node;
      return val;
    }

    Node* cur = head;
    while (cur->next->next) {
      cur = cur->next;
    }

    Node* popped_node = cur->next;
    cur->next = nullptr;
    _size--;
    int val = popped_node->val;
    delete popped_node;
    return val;
  }

  int size() {
    return _size;
  }

  Node* contains(int v) {
    if (_size == 0) {
      return nullptr;
    }

    Node* cur = head;
    while (cur) {
      if (cur->val == v) {
        return cur;
      }
      cur = cur->next;
    }

    return nullptr;
  }

  void print() {
    if (_size == 0) {
      std::cout << "No node exist" << std::endl;
    }

    std::cout << "Total: " << _size << "Nodes" << std::endl;
    std::string output = "";
    Node* cur = head;
    while (cur) {
      output += std::to_string(cur->val) + "->";
      cur = cur->next;
    }
    std::cout << output << std::endl;
  }  
};

int main() {
  SinglyLinkedList sll;
  sll.push_front(1);
  sll.push_front(2);
  sll.pop_back();
  sll.pop_front();
  sll.print();
  // No Nodes

  sll.push_back(1);
  sll.push_back(2);
  sll.push_back(3);
  std::cout << sll.contains(2)->val << std::endl;
  sll.print();
  // 1->2->3->

  return 0;
}