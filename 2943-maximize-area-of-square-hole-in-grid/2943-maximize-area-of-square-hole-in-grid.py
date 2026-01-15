class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: List[int], vBars: List[int]) -> int:
        hBars.sort()
        vBars.sort()

        maxh = 1
        maxv = 1
        hLen = 1
        vLen = 1

        # Horizontal bars
        for i in range(len(hBars) - 1):
            if hBars[i + 1] - hBars[i] == 1:
                hLen += 1
                maxh = max(maxh, hLen)
            else:
                hLen = 1

        # Vertical bars
        for i in range(len(vBars) - 1):
            if vBars[i + 1] - vBars[i] == 1:
                vLen += 1
                maxv = max(maxv, vLen)
            else:
                vLen = 1

        side = min(maxh + 1, maxv + 1)
        return side * side
