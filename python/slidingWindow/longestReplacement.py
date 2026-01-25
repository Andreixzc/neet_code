import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque
from collections import Counter


class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        mymap = Counter()
        ans = 0
        left = 0
        maxFreq = 0

        for right in range(len(s)):
            mymap[s[right]] += 1
            maxFreq = max(maxFreq, mymap[s[right]])
            if (right - left) + 1 - maxFreq > k:
                while (right - left) + 1 - maxFreq > k:
                    mymap[s[left]] -= 1
                    left += 1

            ans = max(ans, (right - left) + 1)

        return ans


def main():
    s = Solution()
    data = [1, 2, 3]


if __name__ == "__main__":
    threading.Thread(target=main).start()
