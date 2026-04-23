import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque


class Solution:

    class TreeNode:
        def __init__(self, val=0, left=None, right=None):
            self.val = val
            self.left = left
            self.right = right

    def maxDepth(self, root):
        if not root:
            return 0

        ans = 0
        stack = [[1,root]]

        while stack:
            depth, node = stack.pop()
            ans = max(depth,ans)

            if node.left:
                stack.append([depth + 1, node.left])
            
            if node.right:
                stack.append([depth + 1, node.right])

       return ans 


def main():
    s = Solution()
    data = [1, 2, 3]


if __name__ == "__main__":
    threading.Thread(target=main).start()
