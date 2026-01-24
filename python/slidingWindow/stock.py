import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l, r = 0, 1
        ans = 0
        while r < len(prices):
            if prices[r] > prices[l]:
                ans = max(ans, prices[r] - prices[l])
            else:
                l = r

            r += 1

        return ans


def main():
    s = Solution()
    data = [10, 1, 5, 6, 7, 1]
    s.maxProfit(data)


if __name__ == "__main__":
    threading.Thread(target=main).start()
