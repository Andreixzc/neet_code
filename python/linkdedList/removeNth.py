import sys
import threading
from typing import List, Tuple, Dict, Set, Optional
from collections import defaultdict, deque


class Solution:

    class ListNode:
        def __init__(self, val=0, next=None):
            self.val = val
            self.next = next

    def removeNthFromEnd(
        self, head: Optional[ListNode], n: int
    ) -> Optional[ListNode]:

        it = head
        size = 0

        while it:
            size = size + 1
            it = it.next

        if size == n:
            return head.next

        it = head
        prev = None

        for i in range(0, size - n):
            prev = it
            it = it.next

        prev.next = it.next
        return head


def main():
    s = Solution()
    data = [1, 2, 3]


if __name__ == "__main__":
    threading.Thread(target=main).start()
