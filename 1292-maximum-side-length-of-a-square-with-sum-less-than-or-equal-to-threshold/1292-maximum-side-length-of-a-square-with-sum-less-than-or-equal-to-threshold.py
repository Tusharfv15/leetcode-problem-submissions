class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        n = len(mat)
        m = len(mat[0])
        ans = 0
        prefix = [[0] * m for _ in range(n)]

        for i in range(n):
            for j in range(m):
                prefix[i][j] = (
                    (prefix[i][j - 1] if j - 1 >= 0 else 0)
                    + (prefix[i - 1][j] if i - 1 >= 0 else 0)
                    - (prefix[i - 1][j - 1] if i - 1 >= 0 and j - 1 >= 0 else 0)
                ) + mat[i][j]

        for i in range(n):
            for j in range(m):
                max_square_len = min(n - i, m - j)
                for offset in range(0, max_square_len):
                    diag_i = i + offset
                    diag_j = j + offset

                    matrix_sum = (
                        prefix[diag_i][diag_j]
                        + (prefix[i - 1][j - 1] if i - 1 >= 0 and j - 1 >= 0 else 0)
                        - (prefix[i - 1][diag_j] if i - 1 >= 0 else 0)
                        - (prefix[diag_i][j - 1] if j - 1 >= 0 else 0)
                    )

                    if matrix_sum > threshold:
                        break
                    else:
                        
                        ans = max(ans,offset+1)

        return ans
