import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mymap = {}
        for s in strs:
            freq = [0] * 26
            for letter in s:
                freq[ord(letter) - ord("a")] += 1
            key = "#".join(map(str, freq))
            if key not in mymap:
                mymap[key] = []
            mymap[key].append(s)
        return list(mymap.values())


def main():
    s = Solution()
    data = ["andrei", "caralho", "huezil"]
    s.groupAnagrams(data)


if __name__ == "__main__":
    threading.Thread(target=main).start()
