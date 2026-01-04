class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        ans = 0
        for num in nums:
            sqrt = math.isqrt(num)
            count = 0
            sm = 0
            for i in range(1, sqrt+1):
                if num % i == 0:

                    if num // i != i:
                        sm += i + num // i
                        count += 2
                    else:
                        sm += i
                        count += 1

            if count == 4:
                ans += sm

        return ans
