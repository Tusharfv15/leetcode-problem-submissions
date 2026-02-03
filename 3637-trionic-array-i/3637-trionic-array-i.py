class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        n = len(nums)
        c1, c2, c3 = 0, 0, 0
        i = 0

        while i + 1 < n and nums[i + 1] > nums[i]:
            c1 = 1
            i = i + 1

        if c1 == 0:
            return False

        while i + 1 < n and nums[i + 1] < nums[i]:
            c2 = 1
            i = i + 1

        if c2 == 0:
            return False

        while i + 1 < n and nums[i + 1] > nums[i]:
            c3 = 1
            i = i + 1

        if c3 == 0:
            return False

        

        return i == n-1
