class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [0]*n


        for i in range(0,n):
            if nums[i] > 0:
                next_index = (i + nums[i])%n
                result[i] = nums[next_index]

            elif nums[i] < 0:
                next_index = (i-abs(nums[i])+n)%n
                result[i] = nums[next_index]

            else:
                result[i] = nums[i]


        return result
        