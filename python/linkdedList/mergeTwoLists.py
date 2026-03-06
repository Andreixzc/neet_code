import sys
import threading
from typing import List, Tuple, Dict, Set, Optional
from collections import defaultdict, deque


class Solution:

    class ListNode:
        def __init__(self, val=0, next=None):
            self.val = val
            self.next = next

    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:

        dummy = ListNode(0)
        head = dummy

        while list1 and list2:
            if list1.val <= list2.val:
                dummy.next = list1
                list1 = list1.next

            else:
                dummy.next = list2
                list2 = list2.next

            dummy = dummy.next

        if list1:
            dummy.next = list1
        else:
            dummy.next = list2
        return head.next


def main():
    s = Solution()
    data = [1, 2, 3]


if __name__ == "__main__":
    threading.Thread(target=main).start()
