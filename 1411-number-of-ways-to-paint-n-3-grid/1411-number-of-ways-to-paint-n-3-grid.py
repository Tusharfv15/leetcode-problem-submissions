class Solution:
    mod = 10**9 + 7

    def solve(self, n, state, states, memo):
        if n == 0:
            return 1

        if (n, state) in memo:
            return memo[(n, state)]

        ans = 0
        for next_state in states:
            conflict = False
            for ch1, ch2 in zip(next_state, state):
                if ch1 == ch2:
                    conflict = True
                    break
            if not conflict:
                ans = (ans + self.solve(n-1, next_state, states, memo)) % self.mod

        memo[(n, state)] = ans
        return ans

    def numOfWays(self, n: int) -> int:
        states = ["RYG", "RGY", "RYR", "RGR", "YRG", "YGR",
                  "YGY", "YRY", "GRY", "GYR", "GRG", "GYG"]

        memo = {}
        ans = 0
        for state in states:
            ans = (ans + self.solve(n-1, state, states, memo)) % self.mod

        return ans
