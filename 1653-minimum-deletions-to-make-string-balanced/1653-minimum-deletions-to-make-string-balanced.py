class Solution:
    def minimumDeletions(self, s: str) -> int:
        st = []
        ans = 0
        n = len(s)
        for i in range(0,n):
            if s[i] == 'a' and st and st[-1] == 'b':
                st.pop()
                ans += 1

            else:
                st.append(s[i])


        return ans
