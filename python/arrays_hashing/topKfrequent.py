mport sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues
import heapq


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq_map = {}
        for num in nums:
            if num in freq_map:
                freq_map[num] += 1
            else:
                freq_map[num] = 1
        heap = []
        for key, value in freq_map.items():
            heapq.heappush(heap,(value,key))
            if len(heap) > k:
                heapq.heappop(heap)

        ans = []
        for i in range(0, k):
            ans.append(heapq.heappop(heap)[1])

        return ans


def main():
    s = Solution()
    data = [1, 2, 2, 3, 3, 3]
    print(s.topKFrequent(data, 2))  # Sample test call


if __name__ == "__main__":
    threading.Thread(target=main).start()
