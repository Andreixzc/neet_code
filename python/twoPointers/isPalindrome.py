import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues


class Solution:
    def isPalindrome(self, s: str) -> bool:
        left = 0
        right = len(s) - 1

        while left < right:
            while left < right and not s[left].isalnum():
                left = left + 1
            while left < right and not s[right].isalnum():
                right = right - 1

            if s[left].lower() != s[right].lower():
                return False

            left = left + 1
            right = right - 1

        return True


def main():
    s = Solution()
    print(s.isPalindrome("Was it a car or a cat I saw?"))


if __name__ == "__main__":
    threading.Thread(target=main).start()
