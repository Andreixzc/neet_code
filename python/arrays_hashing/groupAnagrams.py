import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues


class Solution:

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        myMap = {}
        for string in strs:
            arr = [0] * 26
            for i in range(len(string)):
                arr[122 - ord(string[i])] += 1
            key = str(arr)
            if key in myMap:
                myMap[key].append(string)
            else:
                myMap[key] = [string]

        return list(myMap.values())


def main():
    print("caralho")


if __name__ == "__main__":
    threading.Thread(target=main).start()
