class Solution:
    def minAllOneMultiple(self, k: int) -> int:
        if k%2 == 0:
            return -1

        digits = 1
        prev = 1%k
        st = set()
        while True:
            if prev == 0:
                return digits
            prev = ((prev*10)%k +(1)%k)%k
            if prev not in st:
                st.add(prev)
            else:
                return -1
            digits = digits + 1

        return -1
            
            



        