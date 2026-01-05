class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        neg = 0
        tot_sum = 0
        min_abs_neg = float('inf')
        for i in range(n):
            for j in range(n):
                tot_sum += abs(matrix[i][j])
                if matrix[i][j] < 0:
                    neg+=1
                min_abs_neg = min(min_abs_neg,abs(matrix[i][j]))  

                

        if neg%2 == 0:
            return tot_sum

        else:
            return tot_sum - 2*min_abs_neg

        

