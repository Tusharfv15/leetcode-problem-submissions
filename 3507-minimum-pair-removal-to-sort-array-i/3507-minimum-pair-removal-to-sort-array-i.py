class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        sort = True
        for i in range(len(nums)-1):
            if nums[i] > nums[i+1]:
                sort = False
                break

        if sort:
            return 0
        ops = 0
        while True:
            ops += 1
            minPairSum = float('inf')
            index = -1
            n = len(nums)
            for i in range(n-1,0,-1):
                pairSum = nums[i] + nums[i-1]
                if pairSum <= minPairSum:
                    minPairSum = pairSum
                    index = i

            nums_updated = []
            i = 0
            while i < len(nums):

                if i == index - 1:
                    nums_updated.append(minPairSum)
                    i += 2

                else:
                    nums_updated.append(nums[i])
                    i += 1
            sort = True
            for i in range(len(nums_updated)-1):
                if nums_updated[i] > nums_updated[i+1]:
                    sort = False
                    break
            
            if sort:
                return ops
            nums = nums_updated

        return -1
                    


            





        