class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        nums.extend(nums)
        st = []

        
        i = 2*n-1
        ans = [-1 for i in range(n)]
        while i >=0:

            while len(st) !=0 and st[-1] <= nums[i]:
                st.pop()
            if len(st) == 0 and i < n:
                ans[i] = -1
            if len(st) !=0 and i < n:
                ans[i] = st[-1]

            st.append(nums[i])
            i = i-1
        return ans