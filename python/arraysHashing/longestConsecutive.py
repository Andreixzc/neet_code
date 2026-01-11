import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        myset = set()
        res = 0
        for num in nums:
            myset.add(num)

        for i in range(len(nums)):

            current = nums[i]
            current_best = 1
            if current + 1 in myset:
                continue
            tmp = current - 1
            while tmp in myset:
                current_best = current_best + 1
                tmp = tmp - 1
            res = max(current_best, res)
            current_best = 1

        return res


def main():
    s = Solution()
    data = [0, 3, 2, 5, 4, 6, 1, 1]
    print(s.longestConsecutive(data))


if __name__ == "__main__":
    threading.Thread(target=main).start()
