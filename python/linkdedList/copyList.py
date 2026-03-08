import sys
import threading
from typing import List, Tuple, Dict, Set, Optional
from collections import defaultdict, deque


class Solution:
    class ListNode:
        def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None: self.val = val)
            self.next = next
            self.random = random

        def copyrandomlist(self, head: 'optional[node]') -> 'optional[node]':
            mymap = {}

            it = head
            while it:
                mymap[it] = new ListNode(it.val)
                it = it.next

                for node in mymap:
                    mymap[node].random = mymap[node.random] if node.random else None
                    mymap[node].next = mymap[node.next] if node.next else None

            return mymap[head] if head else None

def main():
    s = Solution()
    data = [1, 2, 3]


if __name__ == "__main__":
    threading.Thread(target=main).start()
