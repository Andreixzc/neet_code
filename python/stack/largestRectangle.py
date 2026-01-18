import sys
    import threading
    from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        foward = [-1] * len(heights)
        backwards = [-1] * len(heights)
        stack = []

        for i, h in enumerate(heights):
            while stack and h < stack[-1][0]:
                foward[stack[-1][1]] = i - stack[-1][1] - 1
                stack.pop()
            stack.append((h, i))

        stack.clear()

        for i in range(len(heights) - 1, -1, -1):
            h = heights[i]
            while stack and h < stack[-1][0]:
                backwards[stack[-1][1]] = stack[-1][1] - i - 1
                stack.pop()
            stack.append((h, i))

        for i in range(len(foward)):
            if foward[i] == -1:
                foward[i] = len(foward) - i - 1

        for i in range(len(backwards)):
            if backwards[i] == -1:
                backwards[i] = i

        ans = 0
        for i in range(len(heights)):
            width = backwards[i] + 1 + foward[i]
            ans = max(ans, width * heights[i])

        return ans


def main():
    s = Solution()
    array = [7, 1, 7, 2, 2, 4]
    print(s.largestRectangleArea(array))


if __name__ == "__main__":
    threading.Thread(target=main).start()
