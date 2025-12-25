class Solution:
    def solve(self, row, col, grid,dp):
        n = len(grid)
        m = len(grid[0])

        if row < 0 or row >= n or col < 0 or col >= m:
            return 0

        if dp[row][col] != -1:
            return dp[row][col]
        ways = 0

        if row - 1 >= 0 and col + 1 < m and grid[row][col] < grid[row-1][col+1]:
            ways = max(ways, 1 + self.solve(row-1, col+1, grid,dp))

        if col + 1 < m and grid[row][col] < grid[row][col+1]:
            ways = max(ways, 1 + self.solve(row, col+1, grid,dp))

        if row + 1 < n and col + 1 < m and grid[row][col] < grid[row+1][col+1]:
            ways = max(ways, 1 + self.solve(row+1, col+1, grid,dp))
        dp[row][col] = ways
        return dp[row][col]

    def maxMoves(self, grid):
        n = len(grid)
        m = len(grid[0])
        ans = 0
        dp = [[-1]*m for i in range(n)]

        for i in range(n):
            ans = max(ans, self.solve(i, 0, grid,dp))

        return ans
