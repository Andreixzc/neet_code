import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1
        while left < right:
            current = numbers[left] + numbers[right]
            if current < target:
                left = left + 1
            elif current > target:
                right = right - 1
            else:
                return [left + 1, right + 1]
        return []


def main():
    s = Solution()
    data = [1, 2, 3]
    s.foo(data)


if __name__ == "__main__":
    threading.Thread(target=main).start()
