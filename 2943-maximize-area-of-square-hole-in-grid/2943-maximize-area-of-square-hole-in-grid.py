class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: List[int], vBars: List[int]) -> int:
        hBars.sort()
        vBars.sort()

        vBarsLen = 1
        hBarsLen = 1
        maxh,maxl = 1,1
        for i in range(len(hBars)-1):
            if hBars[i+1] - hBars[i] == 1:
                hBarsLen += 1
                maxh = max(hBarsLen,maxh)
            else:
                hBarsLen = 1

        
        for i in range(len(vBars)-1):
            if vBars[i+1] - vBars[i] == 1:
                vBarsLen += 1
                maxl = max(vBarsLen,maxl)

            else:
                maxh = max(hBarsLen,maxh)
                vBarsLen = 1

        l = min(maxh+1,maxl+1)
        return l*l
            



        