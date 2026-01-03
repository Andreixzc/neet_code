import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        i = 0
        mymap = {}
        for num in nums:
            complemento = target - num
            if complemento in mymap:
                return [mymap[complemento], i]
            mymap[num] = i
            i += 1

        return [-1, -1]


def main():
    s = Solution()
    data = [1, 2, 3]


if __name__ == "__main__":
    threading.Thread(target=main).start()
