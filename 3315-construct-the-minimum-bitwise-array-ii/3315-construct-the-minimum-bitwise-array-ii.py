class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = []
        for i in range(0,n):
            if nums[i]%2 == 0:
                ans.append(-1)
                continue

            found = False

            for j in range(1,32):
                if nums[i] & (1 << j) > 0:
                    continue

                prev = j - 1
                x = (nums[i]^(1<<(j-1)))
                ans.append(x)
                found = True
                break

            if not found:
                ans.append(-1)

        return ans

        