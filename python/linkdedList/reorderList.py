import sys
import threading
from typing import List, Tuple, Dict, Set, Optional
from collections import defaultdict, deque


class Solution:
    class ListNode:
        def __init__(self, val=0, next=None):
            self.val = val
            self.next = next

    def reorderList(self, head: Optional[ListNode]) -> None:
        it = head
        size = 0
        while it:
            it = it.next
            size = size + 1
        midIndex = size // 2
        it = head
        for i in range(0, midIndex):
            it = it.next
        midNode = it
        midNode.next = None
        it = it.next
        curr = it
        prev = None

        while curr:
            tmpNext = curr.next
            curr.next = prev
            prev = curr
            curr = tmpNext
        revHead = prev

        while revHead:
            tmp = head.next
            head.next = revHead
            revHead = revHead.next
            head.next.next = tmp
            head = tmp


def main():
    s = Solution()
    data = [1, 2, 3]


if __name__ == "__main__":
    threading.Thread(target=main).start()
