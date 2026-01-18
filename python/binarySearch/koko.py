import sys
import threading
import math
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque


class Solution:
    def testar(self, k, h, piles):
        if k == 0:
            return False
        total = 0
        for num in piles:
            total += math.ceil(num / k)
            if total > h:
                return False
        return True

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left = 1
        res = max(piles)
        right = max(piles)
        while left <= right:
            mid = (right + left) // 2
            if self.testar(mid, h, piles):
                res = mid
                right = mid - 1
            else:
                left = mid + 1

        return res


def main():
    s = Solution()
    data = [1, 4, 3, 2]
    h = 9
    print(s.minEatingSpeed(data, h))


if __name__ == "__main__":
    threading.Thread(target=main).start()
