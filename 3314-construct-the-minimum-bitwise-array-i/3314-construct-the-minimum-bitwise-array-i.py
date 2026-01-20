class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = []
        for num in nums:
            found = False
            for i in range(0,num):
                ans = (i | (i+1))
                if ans == num:
                    res.append(i)
                    found = True
                    break
            if not found:
                res.append(-1)
            

        return res


        

        