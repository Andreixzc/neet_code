import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heapappend, heappop  # For priority queues


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if token not in {"+", "-", "*", "/"}:
                stack.append(int(token))
            else:
                b = stack.pop()
                a = stack.pop()
                if token == "+":
                    stack.append(a + b)
                elif token == "-":
                    stack.append(a - b)
                elif token == "*":
                    stack.append(a * b)
                elif token == "/":
                    stack.append(int(a / b))

        return stack[-1]


def main():
    s = Solution()
    tokens = ["1", "2", "+", "3", "*", "4", "-"]
    print(s.evalRPN(tokens))
    pass


if __name__ == "__main__":
    threading.Thread(target=main).start()
