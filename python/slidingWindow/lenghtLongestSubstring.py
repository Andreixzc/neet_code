import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        start = 0
        mymap = {}
        for i in range(len(s)):
            if s[i] in mymap and mymap[s[i]] >= start:
                start = mymap[s[i]] + 1
            mymap[s[i]] = i
            ans = max(ans, i - start + 1)
        return ans


def main():
    s = Solution()
    data = [1, 2, 3]


if __name__ == "__main__":
    threading.Thread(target=main).start()
