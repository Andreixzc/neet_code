import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = [0] * len(nums)
        postfix = [0] * len(nums)
        ans = [0] * len(nums)
        prefix[0] = 1
        postfix[-1] = 1
        for i in range(1, len(nums)):
            prefix[i] = nums[i - 1] * prefix[i - 1]

        for i in range(len(nums) - 2, -1, -1):
            postfix[i] = nums[i + 1] * postfix[i + 1]

        for i in range(len(nums)):
            ans[i] = postfix[i] * prefix[i]
        return ans


def main():
    s = Solution()
    data = [1, 2, 4, 8]
    res = s.productExceptSelf(data)
    print(res)


if __name__ == "__main__":
    threading.Thread(target=main).start()
