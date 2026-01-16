import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues


class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for char in s:
            if char == "[" or char == "(" or char == "{":
                stack.append(char)
            elif len(stack) == 0:
                return False
            elif (
                char == "]"
                and stack[-1] == "["
                or char == ")"
                and stack[-1] == "("
                or char == "}"
                and stack[-1] == "{"
            ):
                stack.pop()
            else:
                return False

        return len(stack) == 0


def main():
    s = Solution()
    data = [1, 2, 3]
    s.foo(data)


if __name__ == "__main__":
    threading.Thread(target=main).start()
