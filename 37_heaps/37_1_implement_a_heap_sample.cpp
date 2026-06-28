#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

int parent(int idx) {
  if (idx == 0) {
    return -1;
  }
  return (idx - 1) / 2;
}

int left_child(int idx) {
  return 2 * idx + 1;
}

int right_child(int idx) {
  return 2 * idx + 2;
}

template<typename T>
class Heap {
private:
  std::vector<T> heap;
  std::function<bool(const T&, const T&)> higher_priority;

  void bubble_up(int idx) {
    if (idx == 0) {
      return;
    }
    int parent_idx = parent(idx);
    if (higher_priority(heap[idx], heap[parent_idx])) {
      std::swap(heap[idx], heap[parent_idx]);
      bubble_up(parent_idx);
    }
  }

  void bubble_down(int idx) {
    int l_i = left_child(idx);
    int r_i = right_child(idx);
    bool is_leaf = l_i >= static_cast<int>(heap.size());
    if (is_leaf) return;

    int child_i = l_i;

    if (r_i < static_cast<int>(heap.size()) && higher_priority(heap[r_i], heap[l_i])) {
      child_i = r_i;
    }

    if (higher_priority(heap[child_i], heap[idx])) {
      std::swap(heap[idx], heap[child_i]);
      bubble_down(child_i);
    }
  }

  void heapify() {
    for (int idx = heap.size() / 2; idx >= 0; idx--) {
      bubble_down(idx);
    }
  }

public:
  Heap(std::function<bool(const T&, const T&)> priority = [](const T& x, const T& y) { return x < y; },
       const std::vector<T>& initial_heap = {})
    : heap(initial_heap), higher_priority(priority) {
    if (!heap.empty()) {
      heapify();
    }
  }

  int size() const {
    return heap.size();
  }

  bool empty() const {
    return heap.empty();
  }

  T top() const {
    if (heap.empty()) {
      throw std::runtime_error("Heap is empty");
    }
    return heap[0];
  }

  void push(const T& elem) {
    heap.push_back(elem);
    bubble_up(heap.size() - 1);
  }

  T pop() {
    if (heap.empty()) {
      throw std::runtime_error("Heap is empty");
    }
    T top_elem = heap[0];
    if (heap.size() == 1) {
      heap.clear();
      return top_elem;
    }
    heap[0] = heap.back();
    heap.pop_back();
    bubble_down(0);
    return top_elem;
  }

  const std::vector<T>& get_heap() const {
    return heap;
  }
};

void print_vector(const std::vector<int>& vec) {
  std::cout << "[";
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << vec[i];
    if (i < vec.size() - 1) std::cout << ", ";
  }
  std::cout << "]";
}

int main() {
  std::cout << "Testing Heap Implementation\n";
  std::cout << "==================================================\n";

  // Test 1: Min Heap (default)
  std::cout << "\n1. Testing Min Heap:\n";
  Heap<int> min_heap;
  std::vector<int> elements = {5, 3, 7, 1, 9, 2, 8};
  std::cout << "   Inserting: ";
  print_vector(elements);
  std::cout << "\n";

  for (int elem : elements) {
    min_heap.push(elem);
  }

  std::cout << "   Heap structure: ";
  print_vector(min_heap.get_heap());
  std::cout << "\n";
  std::cout << "   Top (min): " << min_heap.top() << "\n";

  std::vector<int> result;
  while (min_heap.size() > 0) {
    result.push_back(min_heap.pop());
  }
  std::cout << "   Pop order: ";
  print_vector(result);
  std::cout << "\n";

  std::vector<int> expected = elements;
  std::sort(expected.begin(), expected.end());
  std::cout << "   Expected: ";
  print_vector(expected);
  std::cout << "\n";
  std::cout << (result == expected ? "   ✓ Passed\n" : "   ✗ Failed\n");

  // Test 2: Max Heap
  std::cout << "\n2. Testing Max Heap:\n";
  Heap<int> max_heap([](const int& x, const int& y) { return x > y; });
  std::vector<int> elements2 = {5, 3, 7, 1, 9};
  std::cout << "   Inserting: ";
  print_vector(elements2);
  std::cout << "\n";

  for (int elem : elements2) {
    max_heap.push(elem);
  }

  std::cout << "   Heap structure: ";
  print_vector(max_heap.get_heap());
  std::cout << "\n";
  std::cout << "   Top (max): " << max_heap.top() << "\n";

  std::vector<int> result2;
  while (max_heap.size() > 0) {
    result2.push_back(max_heap.pop());
  }
  std::cout << "   Pop order: ";
  print_vector(result2);
  std::cout << "\n";

  std::vector<int> expected2 = elements2;
  std::sort(expected2.begin(), expected2.end(), std::greater<int>());
  std::cout << "   Expected: ";
  print_vector(expected2);
  std::cout << "\n";
  std::cout << (result2 == expected2 ? "   ✓ Passed\n" : "   ✗ Failed\n");

  // Test 3: Heapify
  std::cout << "\n3. Testing Heapify:\n";
  std::vector<int> arr = {5, 3, 7, 1, 9, 2, 8};
  std::cout << "   Original array: ";
  print_vector(arr);
  std::cout << "\n";

  Heap<int> heap_from_array([](const int& x, const int& y) { return x < y; }, arr);
  std::cout << "   After heapify: ";
  print_vector(heap_from_array.get_heap());
  std::cout << "\n";

  std::vector<int> result3;
  while (heap_from_array.size() > 0) {
    result3.push_back(heap_from_array.pop());
  }
  std::cout << "   Pop order: ";
  print_vector(result3);
  std::cout << "\n";

  std::vector<int> expected3 = arr;
  std::sort(expected3.begin(), expected3.end());
  std::cout << "   Expected: ";
  print_vector(expected3);
  std::cout << "\n";
  std::cout << (result3 == expected3 ? "   ✓ Passed\n" : "   ✗ Failed\n");

  // Test 4: Priority Queue Example
  std::cout << "\n4. Testing Priority Queue (Task Scheduling):\n";
  using Task = std::pair<int, std::string>;
  Heap<Task> task_heap([](const Task& x, const Task& y) { return x.first < y.first; });

  std::vector<Task> tasks = {
    {3, "Medium Task"},
    {1, "Urgent Task"},
    {5, "Low Task"},
    {2, "High Task"}
  };
  std::cout << "   Adding tasks: [(3, Medium Task), (1, Urgent Task), (5, Low Task), (2, High Task)]\n";

  for (const auto& task : tasks) {
    task_heap.push(task);
  }

  std::cout << "   Processing tasks in priority order:\n";
  while (task_heap.size() > 0) {
    Task task = task_heap.pop();
    std::cout << "     Priority " << task.first << ": " << task.second << "\n";
  }

  std::cout << "\n==================================================\n";
  std::cout << "All tests completed!\n";

  return 0;
}
