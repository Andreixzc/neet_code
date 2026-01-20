import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque


class TimeMap:

    def __init__(self):
        self.mymap = {}

    def set(self, key, value, timestamp):
        self.mymap.setdefault(key, []).append((value, timestamp))

    def get(self, key, timestamp):
        if key not in self.mymap:
            return ""

        arr = self.mymap[key]
        left = 0
        right = len(arr) - 1

        while left <= right:
            mid = (right + left) // 2
            if timestamp >= arr[mid][1]:
                left = mid + 1
            else:
                right = mid - 1

        if right < 0:
            return ""

        return arr[right][0]


def main():

    timeMap = TimeMap()
    timeMap.set("alice", "happy", 1)
    print(timeMap.get("alice", 1))
    print(timeMap.get("alice", 2))
    timeMap.set("alice", "sad", 3)
    print(timeMap.get("alice", 3))


if __name__ == "__main__":
    threading.Thread(target=main).start()
