from collections import deque
from typing import List

class Solution:
    def check(self, day, cells, n, m):
        grid = [[0]*m for _ in range(n)]
        for i in range(day + 1):
            r, c = cells[i]
            grid[r-1][c-1] = 1  # water

        q = deque()
        vis = [[0]*m for _ in range(n)]

        for j in range(m):
            if grid[0][j] == 0:
                q.append((0, j))
                vis[0][j] = 1

        while q:
            r, c = q.popleft()
            if r == n - 1:
                return True

            for dr, dc in ((1,0),(-1,0),(0,1),(0,-1)):
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < m:
                    if grid[nr][nc] == 0 and not vis[nr][nc]:
                        vis[nr][nc] = 1
                        q.append((nr, nc))

        return False

    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        l, r = 0, len(cells) - 1
        

        while l <= r:
            mid = (l + r) // 2
            if self.check(mid, cells, row, col):
                
                l = mid + 1
            else:
                r = mid - 1

        return l
