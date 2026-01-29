import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        dq = deque()
        ans = []

        for i in range(len(nums)):
            if len(dq) != 0 and dq[0] <= i - k:
                dq.popleft()

            while len(dq) != 0 and nums[i] > nums[dq[-1]]:
                dq.pop()

            dq.append(i)

            if i >= k - 1:
                ans.append(nums[dq[0]])

        return ans


def main():
    s = Solution()
    data = [1, 2, 3]


if __name__ == "__main__":
    threading.Thread(target=main).start()
