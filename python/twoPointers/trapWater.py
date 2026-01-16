import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues


class Solution:
    def trap(self, heights):
        mb = [0] * len(heights)
        ma = [0] * len(heights)
        mb[0] = -1
        ma[-1] = -1
        ans = 0
        for i in range(1, len(mb), 1):
            mb[i] = max(mb[i - 1], heights[i - 1])
        for i in range(len(mb) - 2, -1, -1):
            ma[i] = max(ma[i + 1], heights[i + 1])
        for i in range(len(mb)):
            sum = min(mb[i], ma[i]) - heights[i]
            if sum > 0:
                ans += sum

        return ans


def main():
    s = Solution()
    heights = [0, 2, 0, 3, 1, 0, 1, 3, 2, 1]
    print(s.trap(heights))


if __name__ == "__main__":
    threading.Thread(target=main).start()
