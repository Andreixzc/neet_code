import sys
import threading
from typing import List, Tuple, Dict, Set, Optional
from collections import defaultdict, deque


class Solution:

    class ListNode:
        def __init__(self, val=0, next=None):
            self.val = val
            self.next = next

    def rev(self, start, end):
        prev = None
        current = start
        stop = end.next

        while current != stop:
            cnext = current.next
            current.next = prev
            prev = current
            current = cnext

        return start

    def reverseKGroup(self, head, k):
        iterator = head
        start = head
        c = 0
        result = None
        prev_tail = None

        while iterator:
            c += 1
            if c == k:
                end = iterator
                next_group_head = iterator.next
                new_tail = self.rev(start, end)
                new_tail.next = next_group_head

                if result is None:
                    result = end
                if prev_tail is not None:
                    prev_tail.next = end

                prev_tail = new_tail
                c = 0
                start = next_group_head
                iterator = next_group_head
                continue

            iterator = iterator.next

        return result if result is not None else head


def main():
    s = Solution()
    data = [1, 2, 3]


if __name__ == "__main__":
    threading.Thread(target=main).start()
