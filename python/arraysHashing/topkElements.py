from typing import List
from heapq import heappush, heappop


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}
        pq = []

        for num in nums:
            if num in freq:
                freq[num] += 1
            else:
                freq[num] = 1

        for key in freq:
            value = freq[key]
            heappush(pq, (value, key))

            if len(pq) > k:
                heappop(pq)

        result = []

        while len(pq) > 0:
            pair = heappop(pq)
            frequency = pair[0]
            number = pair[1]
            result.append(number)

        return result
