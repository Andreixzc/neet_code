import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues


class Solution:
    def twoSum(self, nums, target):
        myMap = {}
        i = 0
        for num in nums:
            currentTarget = target - num
            if currentTarget in myMap:
                return [myMap[currentTarget], i]
            myMap[num] = i
            i += 1


def main():
    



if __name__ == "__main__":
    threading.Thread(target=main).start()
