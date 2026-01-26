import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        freq = defaultdict(int)
        window = defaultdict(int)
        left = 0
        match = 0
        ans = ""
        for c in t:
            freq[c] += 1

        for right in range(len(s)):
            window[s[right]] += 1
            if s[right] in freq and window[s[right]] == freq[s[right]]:
                match += 1
            while match == len(freq):
                tmp = s[left : right + 1]
                if not ans or len(tmp) < len(ans):
                    ans = tmp
                if s[left] in freq and window[s[left]] == freq[s[left]]:
                    match -= 1
                window[s[left]] -= 1
                left += 1

        return ans


def main():
    s = Solution()
    data = [1, 2, 3]


if __name__ == "__main__":
    threading.Thread(target=main).start()
