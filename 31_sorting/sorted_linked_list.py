class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self._size = 0

    def append(self, val):
        new = Node(val)
        if self._size == 0:
            self.head = new
            self.tail = new
        else:
            tail = self.tail
            tail.next = new
            self.tail = new
        self._size += 1

    def pop_front(self):
        if self._size == 0:
            return None
        elif self._size == 1:
            self._size -= 1
            head = self.head
            self.head = None
            self.tail = None
            return head.val
        else:
            self._size -= 1
            head = self.head
            self.head = head.next
            return head.val

    def size(self):
        return self._size

    def peek_front(self):
        if self._size == 0:
            return None
        else:
            return self.head.val

def sorted_linked_list(ssl: SinglyLinkedList, mean: int)->SinglyLinkedList:
    # Early Return
    if ssl.size() == 1:
        return ssl

    # Divide Phase
    lower_ssl = SinglyLinkedList()
    lower_sum = 0
    upper_ssl = SinglyLinkedList()
    upper_sum = 0
    while ssl.size() > 0:
        val = ssl.pop_front()
        if val <= mean:
            lower_ssl.append(val)
            lower_sum += val
        else:
            upper_ssl.append(val)
            upper_sum += val

    if lower_ssl.size() == 0:
        sorted_lower_ssl = None
    else:
        sorted_lower_ssl = sorted_linked_list(lower_ssl, lower_sum / lower_ssl.size())

    if upper_ssl.size() == 0:
        sorted_upper_ssl = None
    else:
        sorted_upper_ssl = sorted_linked_list(upper_ssl, upper_sum / upper_ssl.size())

    if sorted_lower_ssl is None:
        return sorted_upper_ssl
    if sorted_upper_ssl is None:
        return sorted_lower_ssl

    # Conquer Phase
    sorted_ssl = SinglyLinkedList()
    while sorted_lower_ssl.size() > 0 or sorted_upper_ssl.size() > 0:
        if sorted_lower_ssl.size() == 0:
            sorted_ssl.append(sorted_upper_ssl.pop_front())
        elif sorted_upper_ssl.size() == 0:
            sorted_ssl.append(sorted_lower_ssl.pop_front())
        else:
            if sorted_lower_ssl.peek_front() <= sorted_upper_ssl.peek_front():
                sorted_ssl.append(sorted_lower_ssl.pop_front())
            else:
                sorted_ssl.append(sorted_upper_ssl.pop_front())

    return sorted_ssl

def print_ssl(ssl: SinglyLinkedList):
    output = "head -> "
    while ssl.size() > 0:
        node = ssl.pop_front()
        output += f"""{node} -> """

    output += "tail"
    print(output)

if __name__ == "__main__":
    # Example1
    ssl = SinglyLinkedList()
    ssl.append(3)
    ssl.append(2)
    ssl.append(4)
    ssl.append(5)
    ssl.append(1)
    sorted_ssl = sorted_linked_list(ssl, ssl.head.val)
    print_ssl(sorted_ssl)

    # Example2
    ssl = SinglyLinkedList()
    ssl.append(8)
    ssl.append(2)
    ssl.append(4)
    ssl.append(7)
    ssl.append(5)
    ssl.append(1)
    ssl.append(6)
    sorted_ssl = sorted_linked_list(ssl, ssl.head.val)
    print_ssl(sorted_ssl)