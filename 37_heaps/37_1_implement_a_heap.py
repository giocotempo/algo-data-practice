def parent(idx: int):
  if idx == 0:
    return -1
  return (idx - 1) // 2

def left_child(idx: int):
  return 2 * idx + 1

def right_child(idx: int):
  return 2 * idx + 2

class Heap:
  def __init__(self, higher_priority=lambda x, y: x < y, heap=None):
    self.heap = heap if heap is not None else []
    self.higher_priority = higher_priority
    if heap:
      self.heapify()
  
  def size(self):
    return len(self.heap)
  
  def top(self):
    if not self.heap:
      return None
    return self.heap[0]
  
  def push(self, elem):
    self.heap.append(elem)
    self.bubble_up(len(self.heap)-1)

  def bubble_up(self, idx):
    if idx == 0:
      return
    parent_idx = parent(idx)
    if self.higher_priority(self.heap[idx], self.heap[parent_idx]):
      self.heap[idx], self.heap[parent_idx] = self.heap[parent_idx], self.heap[idx]
      self.bubble_up(parent_idx)
  
  def pop(self):
    if not self.heap: return None
    top = self.heap[0]
    if len(self.heap) == 1:
      self.heap = []
      return top
    self.heap[0] = self.heap[-1]
    self.heap.pop()
    self.bubble_down(0)
    return top
  
  def bubble_down(self, idx):
    l_i, r_i = left_child(idx), right_child(idx)
    is_leaf = l_i >= len(self.heap)
    if is_leaf: return
    child_i = l_i
    
    if r_i < len(self.heap) and self.higher_priority(self.heap[r_i], self.heap[l_i]):
      child_i = r_i
    
    if self.higher_priority(self.heap[child_i], self.heap[idx]):
      self.heap[idx], self.heap[child_i] = self.heap[child_i], self.heap[idx]
      self.bubble_down(child_i)

  def heapify(self):
    for idx in range(len(self.heap)//2, -1, -1):
      self.bubble_down(idx)

if __name__ == "__main__":
  print("Testing Heap Implementation\n" + "="*50)

  # Test 1: Min Heap (default)
  print("\n1. Testing Min Heap:")
  min_heap = Heap()
  elements = [5, 3, 7, 1, 9, 2, 8]
  print(f"   Inserting: {elements}")

  for elem in elements:
    min_heap.push(elem)

  print(f"   Heap structure: {min_heap.heap}")
  print(f"   Top (min): {min_heap.top()}")

  result = []
  while min_heap.size() > 0:
    result.append(min_heap.pop())
  print(f"   Pop order: {result}")
  print(f"   Expected: {sorted(elements)}")
  print(f"   ✓ Passed" if result == sorted(elements) else f"   ✗ Failed")

  # Test 2: Max Heap
  print("\n2. Testing Max Heap:")
  max_heap = Heap(higher_priority=lambda x, y: x > y)
  elements = [5, 3, 7, 1, 9]
  print(f"   Inserting: {elements}")

  for elem in elements:
    max_heap.push(elem)

  print(f"   Heap structure: {max_heap.heap}")
  print(f"   Top (max): {max_heap.top()}")

  result = []
  while max_heap.size() > 0:
    result.append(max_heap.pop())
  print(f"   Pop order: {result}")
  expected = sorted(elements, reverse=True)
  print(f"   Expected: {expected}")
  print(f"   ✓ Passed" if result == expected else f"   ✗ Failed")

  # Test 3: Heapify
  print("\n3. Testing Heapify:")
  arr = [5, 3, 7, 1, 9, 2, 8]
  print(f"   Original array: {arr}")
  heap_from_array = Heap(heap=arr.copy())
  print(f"   After heapify: {heap_from_array.heap}")

  result = []
  while heap_from_array.size() > 0:
    result.append(heap_from_array.pop())
  print(f"   Pop order: {result}")
  print(f"   Expected: {sorted(arr)}")
  print(f"   ✓ Passed" if result == sorted(arr) else f"   ✗ Failed")

  # Test 4: Priority Queue Example
  print("\n4. Testing Priority Queue (Task Scheduling):")
  task_heap = Heap(higher_priority=lambda x, y: x[0] < y[0])  # (priority, task_name)

  tasks = [(3, "Medium Task"), (1, "Urgent Task"), (5, "Low Task"), (2, "High Task")]
  print(f"   Adding tasks: {tasks}")

  for task in tasks:
    task_heap.push(task)

  print("   Processing tasks in priority order:")
  while task_heap.size() > 0:
    priority, task_name = task_heap.pop()
    print(f"     Priority {priority}: {task_name}")

  print("\n" + "="*50)
  print("All tests completed!")