from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues


class Solution:
    def longestConsecutive(self, nums):
        my_set = set()
        ans = 0
        for num in nums:
            my_set.add(num)

        while len(my_set) > 0:
            item = my_set.pop()
            currCount = 1
            while item + 1 in my_set:
                currCount += 1
                my_set.remove(item + 1)
            ans = max(currCount, ans)
        return ans


def main():
    s = Solution()
    nums = [2, 20, 4, 10, 3, 4, 5]
    print(s.longestConsecutive(nums=nums))


main()
