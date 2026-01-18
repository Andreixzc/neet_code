import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues


class Solution:
    def carFleet(
        self, target: int, position: List[int], speed: List[int]
    ) -> int:
        cars = []
        fleet = 1
        for i in range(len(position)):
            cars.append((position[i], speed[i]))

        cars.sort(key=lambda x: x[0], reverse=True)

        stack = []

        for pos, sp in cars:
            arrival = (target - pos) / sp
            if not stack:
                stack.append(arrival)
            elif arrival <= stack[-1]:
                continue
            else:
                fleet += 1
                stack.append(arrival)

        return fleet


def main():
    s = Solution()
    data = [1, 2, 3]
    s.foo(data)


if __name__ == "__main__":
    threading.Thread(target=main).start()
