class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()
        l = 0
        r = 1
        if n == 1:
            return 0
        max_len = 0
        while r < n:
            if nums[r] <= k*nums[l]:
                max_len = max(max_len,r-l+1)

            else:
                while l < r and nums[r] > k*nums[l]:
                    l+=1

                max_len = max(max_len,r-l+1)

            r += 1

        return n - max_len

        