import threading


class LRUCache:

    class ListNode:
        def __init__(self, val=0, next=None, prev=None, key=0):
            self.val = val
            self.next = next
            self.prev = prev
            self.key = key

    def __init__(self, capacity: int):
        self.node_map = {}
        self.head = self.ListNode()
        self.tail = self.ListNode()
        self.current_capacity = 0
        self.capacity = capacity
        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, key: int) -> int:
        if key not in self.node_map:
            return -1

        current = self.node_map[key]
        current.prev.next = current.next
        current.next.prev = current.prev
        current.next = self.head.next
        current.prev = self.head
        self.head.next.prev = current
        self.head.next = current
        return current.val

    def put(self, key: int, value: int) -> None:
        if key in self.node_map:
            self.node_map[key].val = value
            self.get(key)
            return

        current = self.ListNode(value, key=key)
        current.next = self.head.next
        current.prev = self.head
        self.head.next.prev = current
        self.head.next = current
        self.node_map[key] = current

        if self.current_capacity < self.capacity:
            self.current_capacity += 1
        else:
            lru = self.tail.prev
            lru.prev.next = self.tail
            self.tail.prev = lru.prev
            del self.node_map[lru.key]


def main():
    cache = LRUCache(2)
    cache.put(1, 1)
    cache.put(2, 2)
    cache.put(3, 3)
    print(cache.node_map.keys())


if __name__ == "__main__":
    threading.Thread(target=main).start()
