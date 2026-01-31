class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        n = len(letters)

        l = 0
        r = n-1
        ans = "*"
        while l <= r:
            mid = r + (l-r)//2
            if letters[mid] > target:
                ans = letters[mid]
                r = mid - 1

            else:
                l = mid + 1

        if ans == "*":
            return letters[0]

        return ans
        