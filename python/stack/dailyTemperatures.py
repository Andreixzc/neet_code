import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        st = []
        ans = [0] * len(temperatures)
        for i, t in enumerate(temperatures):
            if not st:
                st.append((t, i))
            elif t > st[-1][0]:
                while st and t > st[-1][0]:
                    ans[st[-1][1]] = i - st[-1][1]
                    st.pop()
                st.append((t, i))
            else:
                st.append((t, i))

        return ans


def main():
    s = Solution()
    data = [1, 2, 3]
    s.dailyTemperatures(data)


if __name__ == "__main__":
    threading.Thread(target=main).start()
