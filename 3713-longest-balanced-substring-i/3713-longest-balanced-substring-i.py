class Solution:
    def longestBalanced(self, s: str) -> int:
        n = len(s)
        ans = 0
        for i in range(0,n):
            store_count = [0]*26
            for j in range(i,n):
                store_count[ord(s[j])-ord('a')]+=1
                count = -1
                valid = True
                for char_count in store_count:
                    if count == -1 and char_count != 0:
                        count = char_count

                    elif char_count !=0 and char_count != count:
                        valid = False
                        break

                if valid:
                    ans = max(ans,j-i+1)

        return ans

        