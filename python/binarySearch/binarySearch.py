import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues


class Solution:
    def searchRecursive(nums, target, left, right):
        if left > right:
            return -1
        mid = (right + left) // 2
        if nums[mid] == target:
            return mid
        if nums[mid] > target:
            return searchRecursive(nums, target, left, mid - 1)
        else:
            return searchRecursive(nums, target, mid + 1, right)

    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return -1


def main():
    s = Solution()
    data = [1, 2, 3]
    print(data[len(data) - 1])
    s.search(data, 3123)


if __name__ == "__main__":
    threading.Thread(target=main).start()
