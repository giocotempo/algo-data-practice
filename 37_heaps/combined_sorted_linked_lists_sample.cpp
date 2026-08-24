#include <cstddef>
#include <functional>
#include <iostream>
#include <memory>
#include <queue>
#include <utility>
#include <vector>

struct Node {
  explicit Node(int value) : val(value) {}

  int val;
  std::unique_ptr<Node> next;
};

class SinglyLinkedList {
private:
  std::unique_ptr<Node> head;
  Node* tail = nullptr;
  std::size_t size_ = 0;

public:
  SinglyLinkedList() = default;
  SinglyLinkedList(const SinglyLinkedList&) = delete;
  SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;
  SinglyLinkedList(SinglyLinkedList&&) = default;
  SinglyLinkedList& operator=(SinglyLinkedList&&) = default;

  void append(int val) {
    auto node = std::make_unique<Node>(val);
    Node* new_tail = node.get();

    if (size_ == 0) {
      head = std::move(node);
    } else {
      tail->next = std::move(node);
    }

    tail = new_tail;
    ++size_;
  }

  std::unique_ptr<Node> pop_front() {
    if (size_ == 0) {
      return nullptr;
    }

    std::unique_ptr<Node> old_head = std::move(head);
    head = std::move(old_head->next);
    --size_;

    if (size_ == 0) {
      tail = nullptr;
    }

    return old_head;
  }

  std::size_t size() const {
    return size_;
  }
};

SinglyLinkedList combined_sorted_linked_lists(
    const std::vector<SinglyLinkedList*>& slls) {
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

  for (SinglyLinkedList* sll : slls) {
    while (sll->size() > 0) {
      std::unique_ptr<Node> node = sll->pop_front();
      min_heap.push(node->val);
    }
  }

  SinglyLinkedList combined;
  while (!min_heap.empty()) {
    combined.append(min_heap.top());
    min_heap.pop();
  }

  return combined;
}

int main() {
  SinglyLinkedList sll1;
  sll1.append(1);
  sll1.append(6);

  SinglyLinkedList sll2;
  sll2.append(1);
  sll2.append(4);
  sll2.append(6);

  SinglyLinkedList sll3;
  sll3.append(3);
  sll3.append(7);

  SinglyLinkedList sll =
      combined_sorted_linked_lists({&sll1, &sll2, &sll3});

  while (sll.size() > 0) {
    std::unique_ptr<Node> node = sll.pop_front();
    std::cout << node->val << '\n';
  }

  return 0;
}
