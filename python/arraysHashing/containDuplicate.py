import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues


class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        myset = set()
        for num in nums:
            if num in myset:
                return True
            myset.add(num)
        return False


def main():
    s = Solution()
    data = [1, 2, 3]
    print(s.hasDuplicate(data))


if __name__ == "__main__":
    threading.Thread(target=main).start()
