import sys
import threading
from typing import List, Tuple, Dict, Set
from collections import defaultdict, deque


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        largura = len(matrix[0])
        altura = len(matrix)
        left = 0
        right = (largura * altura) - 1

        while left <= right:
            mid = (left + right) // 2
            i = mid // largura
            j = mid % largura
            if target == matrix[i][j]:
                return True
            elif target > matrix[i][j]:
                left = mid + 1
            else:
                right = mid - 1

        return False


def main():
    s = Solution()
    data = [[1, 2, 4, 8], [10, 11, 12, 13], [14, 20, 30, 40]]
    print(s.searchMatrix(data, 10))


if __name__ == "__main__":
    threading.Thread(target=main).start()
