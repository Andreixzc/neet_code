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

    def dfs(self, node, current_height):
        if not node:
            return current_height

        return max(
            self.dfs(node.left, current_height + 1),
            self.dfs(node.right, current_height + 1),
        )

    def maxDepthRec(self, root):

        if not root:
            return 0

        return self.dfs(root, 0)

    def maxDepth(self, root):

        if not root:
            return 0

        ans = 0
        stack = [(root, 1)]

        while stack:
            node = stack.pop()
            ans = max(node[1], ans)
            if node[0].left:
                stack.append((node[0].left, node[1] + 1))
            if node[0].right:
                stack.append((node[0].right, node[1] + 1))

        return ans


def main():
    s = Solution()
    data = [1, 2, 3]


if __name__ == "__main__":
    threading.Thread(target=main).start()
