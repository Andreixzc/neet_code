import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues


class Solution:
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False

        arr = [0] * 26
        for i in range(len(s)):
            arr[122 - ord(s[i])] += 1
            arr[122 - ord(t[i])] -= 1

        for num in arr:
            if num != 0:
                return False

        return True


def main():
    s = Solution()
    print(s.isAnagram("a", "a"))


if __name__ == "__main__":
    threading.Thread(target=main).start()
