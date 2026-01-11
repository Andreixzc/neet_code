import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque

# from heapq import heappush, heappop  # For priority queues


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_map = {}
        col_map = {}
        block_map = {}

        for i in range(9):
            for j in range(9):
                current = board[i][j]
                if current == ".":
                    continue
                block = (i // 3) * 3 + (j // 3)
                row_map.setdefault(i, set())
                col_map.setdefault(j, set())
                block_map.setdefault(block, set())
                if current in row_map[i]:
                    return False
                if current in col_map[j]:
                    return False
                if current in block_map[block]:
                    return False

                row_map[i].add(current)
                col_map[j].add(current)
                block_map[block].add(current)
        return True


def main():
    s = Solution()


if __name__ == "__main__":
    threading.Thread(target=main).start()
