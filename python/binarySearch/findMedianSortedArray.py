import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:

        if len(nums1) >= len(nums2):
            bigger = nums1
            smaller = nums2
        else:
            bigger = nums2
            smaller = nums1

        left = 0
        right = len(smaller)
        ans = []

        while left <= right:
            p1 = (left + right) // 2
            p2 = ((len(bigger) + len(smaller) + 1) // 2) - p1
            maxLeft1 = float("-inf") if p1 == 0 else smaller[p1 - 1]
            minRight1 = float("inf") if p1 == len(smaller) else smaller[p1]
            maxLeft2 = float("-inf") if p2 == 0 else bigger[p2 - 1]
            minRight2 = float("inf") if p2 == len(bigger) else bigger[p2]
            if maxLeft1 <= minRight2 and maxLeft2 <= minRight1:
                ans.append(maxLeft1)
                ans.append(maxLeft2)
                ans.append(minRight1)
                ans.append(minRight2)
                break
            elif maxLeft1 > minRight2:
                right = p1 - 1
            else:
                left = p1 + 1

        ans.sort()
        if (len(bigger) + len(smaller)) % 2 == 0:
            return (ans[1] + ans[2]) / 2
        else:
            return ans[1]


def main():
    s = Solution()
    nums1 = [1, 2, 3]
    nums2 = [1, 2, 3, 4, 5, 6]
    s.findMedianSortedArrays(nums1, nums2)


if __name__ == "__main__":
    threading.Thread(target=main).start()
