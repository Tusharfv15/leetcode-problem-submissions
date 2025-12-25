class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort()
        happiness.reverse()

        counter = 0
        i = 0
        n = len(happiness)
        ans = 0
        while i < n and k > 0:
            val = happiness[i]-counter
            if val > 0:
                ans = ans + val
                k = k-1
            else:
                break
            counter = counter + 1
            i = i + 1

        return ans


