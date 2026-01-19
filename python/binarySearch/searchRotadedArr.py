import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque


class Solution:
    def bsearch(self, nums, start, end, target):
        left = start
        right = end
        while left <= right:
            mid = (right + left) // 2
            if target == nums[mid]:
                return mid
            if target > nums[mid]:
                left = mid + 1
            else:
                right = mid - 1

        return -1

    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = (right + left) // 2
            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid

        rotation = left

        if target >= nums[rotation] and target <= nums[len(nums) - 1]:
            return self.bsearch(nums, rotation, len(nums) - 1, target)
        else:
            return self.bsearch(nums, 0, rotation - 1, target)


def main():
    s = Solution()
    data = [4, 5, 6, 7, 0, 1, 2]
    print(s.search(data, 0))


if __name__ == "__main__":
    threading.Thread(target=main).start()
