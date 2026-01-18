import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque


class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = (right + left) // 2
            if nums[left] <= nums[right]:
                return nums[left]
            elif nums[mid] >= nums[left]:
                left = mid + 1
            else:
                right = mid


def main():
    s = Solution()
    data = [4, 5, 6, 7, 1, 2, 3]
    print(s.findMin(data))


if __name__ == "__main__":
    threading.Thread(target=main).start()
