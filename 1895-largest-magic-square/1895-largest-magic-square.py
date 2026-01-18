class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        row_ps = [[0]*m for _ in range(n)]
        col_ps = [[0]*m for _ in range(n)]
        ans = 1
        for i in range(n):
            for j in range(m):
                if j == 0:
                    row_ps[i][j] = grid[i][j]
                else:
                    row_ps[i][j] = row_ps[i][j-1] + grid[i][j]
                if i == 0:
                    col_ps[i][j] = grid[i][j]
                else:
                    col_ps[i][j] = col_ps[i-1][j] + grid[i][j]

        
        for i in range(n):
            for j in range(m):
                maxLen = min(n-i,m-j)

                for l in range(1,maxLen+1):
                    sums = set()
                    for rows in range(i,i+l):
                        row_sum = row_ps[rows][j+l-1]-(row_ps[rows][j-1] if j > 0 else 0)
                        sums.add(row_sum)
                    for col in range(j,j+l):
                        col_sum = col_ps[i+l-1][col] - (col_ps[i-1][col] if i > 0 else 0)
                        sums.add(col_sum)

                    d1 = 0
                    for k in range(l):
                        d1 += grid[i + k][j + k]
                    sums.add(d1)

                    # anti-diagonal
                    d2 = 0
                    for k in range(l):
                        d2 += grid[i + k][j + l - 1 - k]
                    sums.add(d2)

                    if len(sums) == 1:
                        ans = max(ans, l)

        return ans
                    