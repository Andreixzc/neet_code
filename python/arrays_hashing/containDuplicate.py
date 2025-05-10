import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues


class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        mySet = set()
        for num in nums:
            if num in mySet:
                return True
            mySet.add(num)
        return False

    def foo(self, data) -> None:
        # freq_map: Dict[int, int] = defaultdict(int)
        # seen: Set[int] = set()
        # stack: List[int] = []
        # queue: Deque[int] = deque()
        # graph: Dict[int, List[int]] = defaultdict(list)
        # min_heap: List[int] = []
        print("hue")
        pass


def main():
    s = Solution()
    data = [1, 2, 3]
    s.foo(data)


if __name__ == "__main__":
    threading.Thread(target=main).start()
