class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)
        if digits[n-1] != 9:
            digits[n-1]+=1

        else:
            i = n-1
            while i >=0 and digits[i] == 9:
                i = i - 1

            if i == -1:
                digits.insert(0,1)
                n = len(digits)
                for i in range(1,n):
                    digits[i] = 0

            else:
                digits[i] += 1
                for i in range(i+1,n):
                    digits[i] = 0

        return digits
            