class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        n = len(nums)/2
        mpp = defaultdict(int)
        for num in nums:
            mpp[num]+=1
            if mpp[num] == n:
                return num

        return -1
