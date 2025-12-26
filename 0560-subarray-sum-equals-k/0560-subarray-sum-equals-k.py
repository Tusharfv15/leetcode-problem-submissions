class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mpp = {}
        mpp[0] = 1
        preSum = 0
        ans = 0

        for num in nums:
            preSum += num
            rem = preSum - k
            if rem in mpp:
                ans =  ans + mpp[rem]
            if preSum not in mpp:
                mpp[preSum] = 1
            else:
                mpp[preSum] = mpp[preSum]+1
        return ans


        