import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues


class solution:
    def encode(self, strs: list[str]) -> str:
        encoded = ""
        for s in strs:
            encoded += str(len(s))
            encoded += "@"
            encoded += s
        return encoded

    def decode(self, s: str) -> List[str]:
        ans = []
        tmp = ""
        i = 0
        while i < len(s):
            if s[i] == "@":
                length = int(tmp)
                decoded = ""
                i = i + 1
                k = 0
                while k < length:
                    decoded += s[k + i]
                    k = k + 1
                i = k + i
                ans.append(decoded)
                tmp = ""
                continue
            tmp += s[i]
            i = i + 1

        return ans


def main():
    sol = solution()
    raw = ["Hello", "world", "djsjdhuhsd"]
    encoded = sol.encode(raw)
    print(encoded)
    print(sol.decode(encoded))

    pass


if __name__ == "__main__":
    threading.Thread(target=main).start()
    pass
