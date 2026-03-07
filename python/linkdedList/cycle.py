import sys
import threading
from typing import List, Tuple, Dict, Set, Optional
from collections import defaultdict, deque


class Solution:

    class ListNode:
        def __init__(self, val=0, next=None):
            self.val = val
            self.next = next

    def hasCycle(self, head: Optional[ListNode]) -> bool:

        fast = head
        slow = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True

        return False


def main():
    s = Solution()
    data = [1, 2, 3]


if __name__ == "__main__":
    threading.Thread(target=main).start()
