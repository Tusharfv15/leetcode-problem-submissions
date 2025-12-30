class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        ans = 0

        for i in range(n - 2):
            for j in range(m - 2):
                st = set()
                store_row_sum = [0]*n

                for row in range(i, i + 3):

                    for col in range(j, j + 3):
                        number = grid[row][col]
                        if number >= 1 and number <= 9 and number not in st:
                            store_row_sum[row]+=number
                            st.add(number)

                if len(st) == 9:
                    left_diag_sum = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2]
                    right_diag_sum = (
                        grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j]
                    )
                    store_col_sum = [0]*m
                
                    for col in range(j,j+3):
                        for row in range(i,i+3):
                            store_col_sum[col]+=grid[row][col]
                    
                    if store_row_sum[i] == store_row_sum[i+1] and store_row_sum[i+1] == store_row_sum[i+2] and store_col_sum[j] == store_col_sum[j+1] and store_col_sum[j+1] == store_col_sum[j+2] and left_diag_sum == right_diag_sum:
                        ans = ans + 1

        return ans
