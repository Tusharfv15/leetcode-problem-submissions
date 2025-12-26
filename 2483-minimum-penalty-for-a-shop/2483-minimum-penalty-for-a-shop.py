class Solution:
    def bestClosingTime(self, customers: str) -> int:
        n = len(customers)
        
        yesCount = [0] * n
        noCount = [0] * n
        
        yesCount[0] = 1 if customers[0] == "Y" else 0
        noCount[0] = 1 if customers[0] == "N" else 0
        
        for i in range(1, n):
            yesCount[i] = yesCount[i - 1] + (1 if customers[i] == "Y" else 0)
            noCount[i] = noCount[i - 1] + (1 if customers[i] == "N" else 0)
        
        penalty = float("inf")
        ans = 0
        
        for closingTime in range(n + 1):
            if closingTime == 0:
                nCount = 0
                yCount = yesCount[n - 1]
            else:
                nCount = noCount[closingTime - 1]
                yCount = yesCount[n - 1] - yesCount[closingTime - 1]
            
            if nCount + yCount < penalty:
                penalty = nCount + yCount
                ans = closingTime
        
        return ans