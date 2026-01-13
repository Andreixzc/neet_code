import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues


class Solution:
    def maxArea(self, heights: List[int]) -> int:
        left = 0
        right = len(heights) - 1
        ans = 0

        while (left < right):
            current = min(heights[left], heights[right]) * (right - left)
            if heights[left] < heights[right]:
                left+=1
            elif heights[left] > heights[right]:
                right-=1
            else:
                left+=1
                right-=1
            ans = max(current,ans)

        return ans



def main():


if __name__ == "__main__":
    threading.Thread(target=main).start()

