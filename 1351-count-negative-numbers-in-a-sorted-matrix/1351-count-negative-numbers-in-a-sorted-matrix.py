class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        m = len(grid[0])
        ans = 0

        for row in grid:
            l, r = 0, m - 1

            while l < r:
                mid = (l + r) // 2
                if row[mid] >= 0:
                    l = mid + 1
                else:
                    r = mid

            # post-check
            if row[l] < 0:
                ans += m - l

        return ans
