import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1_freq = Counter()
        window = Counter()

        for c in s1:
            s1_freq[c] += 1
        for i in range(len(s2)):
            window[s2[i]] += 1

            if i >= len(s1):
                remove = s2[i - len(s1)]
                window[remove] -= 1
                if window[remove] == 0:
                    del window[remove]

            if s1_freq == window:
                return True

        return False


def main():
    s = Solution()
    data = [1, 2, 3]


if __name__ == "__main__":
    threading.Thread(target=main).start()
