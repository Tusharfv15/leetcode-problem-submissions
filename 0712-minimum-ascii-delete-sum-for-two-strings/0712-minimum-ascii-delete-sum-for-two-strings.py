class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        n = len(s1)
        m = len(s2)

        
        dp = [[0]*(m+1) for _ in range(n+1)]

        for i in range(n-1, -1, -1):
            for j in range(m-1, -1, -1):
                if s1[i] == s2[j]:
                    dp[i][j] = ord(s1[i]) + dp[i+1][j+1]
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1])

        
        lcs_chars = []
        i, j = 0, 0

        while i < n and j < m:
            if s1[i] == s2[j]:
                lcs_chars.append(s1[i])
                i += 1
                j += 1
            elif dp[i+1][j] > dp[i][j+1]:
                i += 1
            else:
                j += 1

        longest_subsequence = "".join(lcs_chars)

        
        asci1 = sum(ord(c) for c in s1)
        asci2 = sum(ord(c) for c in s2)
        asci3 = sum(ord(c) for c in longest_subsequence)

        return asci1 + asci2 - 2 * asci3
