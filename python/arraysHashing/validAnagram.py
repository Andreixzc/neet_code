import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        mymap = {}

        for i in range(len(s)):
            mymap[s[i]] = mymap.get(s[i], 0) + 1
            mymap[t[i]] = mymap.get(t[i], 0) - 1

        for v in mymap.values():
            if v != 0:
                return False

        return True


def main():
    if __name__ == "__main__":
        threading.Thread(target=main).start()
