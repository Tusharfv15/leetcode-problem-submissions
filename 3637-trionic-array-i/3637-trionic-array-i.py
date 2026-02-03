class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        n = len(nums)
        c1,c2,c3 = 0,0,0
        i = 0
        

      
        while i + 1 < n and nums[i+1] > nums[i]:
            c1 = 1
            i = i + 1

        while i + 1 < n and nums[i+1] < nums[i]:
            c2 = 1
            i =  i + 1

        while i + 1 < n and nums[i+1] > nums[i]:
            c3 = 1
            i = i + 1


        if not c1 or not c2 or not c3:
            return False


        return i == n-1
