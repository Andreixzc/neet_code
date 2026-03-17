import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque


class Solution:

    def findDuplicate(self, nums: List[int]) -> int:

        for i in range(0, len(nums)):
            index = abs(nums[i]) - 1
            if nums[index] < 0:
                return abs(nums[i])
            nums[index] = nums[index] * -1

        return -1


def main():
    s = Solution()
    data = [1, 2, 3, 2, 2]
    s.findDuplicate(data)


if __name__ == "__main__":
    threading.Thread(target=main).start()
