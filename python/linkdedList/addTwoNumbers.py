import sys
import threading
from typing import List, Tuple, Dict, Set, Optional
from collections import defaultdict, deque


class Solution

    class ListNode:
        def __init__(self, val=0, next=None):
            self.val = val
            self.next = next

    def addTwoNumbers(
        self, l1: "Solution.ListNode", l2: "Solution.ListNode"
    ) -> "Solution.ListNode":

        dummy = ListNode()
        current = dummy
        carry = 0

        while l1 or l2:

            l1_val = l1.val if l1 else 0
            l2_val = l2.val if l2 else 0

            currSum = l1_val + l2_val + carry
            carry = currSum // 10
            current.next = ListNode(currSum % 10)
            current = current.next

            if l1: l1 = l1.next
            if l2: l2 = l2.next


        if carry > 0:
            current.next = ListNode(carry)

        return dummy.next
    


def main():
    s = Solution()
    data = [1, 2, 3]


if __name__ == "__main__":
    threading.Thread(target=main).start()
