class Solution:
    def solve(self, i, j, n, m, nums1, nums2, dp):
        if i == n or j == m:
            return float('-inf')

        if dp[i][j] is not None:
            return dp[i][j]

        
        op1 = self.solve(i+1,j,n,m,nums1,nums2,dp)
        op2 = self.solve(i,j+1,n,m,nums1,nums2,dp)
        op5 = self.solve(i+1,j+1,n,m,nums1,nums2,dp)
        op3 = nums1[i]*nums2[j]
        op4 = nums1[i]*nums2[j] + self.solve(i+1,j+1,n,m,nums1,nums2,dp)
        dp[i][j] = max(op1,op2,op3,op4,op5)
        return max(op1,op2,op3,op4,op5)


    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n, m = len(nums1), len(nums2)
        dp = [[None] * m for _ in range(n)]
        return self.solve(0, 0, n, m, nums1, nums2, dp)
