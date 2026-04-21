import sys
import threading
from typing import List, Tuple, Dict, Set, Optional
from collections import defaultdict, deque


class Solution:
    class ListNode:
        def __init__(self, val=0, next=None):
            self.val = val
            self.next = next

    def merge(l1, l2):

        if not l1:
            return l2
        if not l2:
            return l1

        if l1.val < l2.val:
            it = l1
            l1 = l1.next
        else:
            it = l2
            l2 = l2.next

        head = it

        while l1 or l2:

            if l1.val < l2.val:
                it.next = l1
                it = l1
                l1 = l1.next
            else:
                it.next = l2
                it = l2
                l2 = l2.next

        if l1:
            it.next = l2
        else:
            it.next = l1

        return head

    def mergeKLists(
        self, lists: List[Optional[ListNode]]
    ) -> Optional[ListNode]:
        for i in range(1, len(lists)):
            lists[i] = self.merge(lists[lists[i], lists[i - 1]])
        return lists[-1]


def main():
    s = Solution()
    data = [1, 2, 3]


if __name__ == "__main__":
    threading.Thread(target=main).start()
