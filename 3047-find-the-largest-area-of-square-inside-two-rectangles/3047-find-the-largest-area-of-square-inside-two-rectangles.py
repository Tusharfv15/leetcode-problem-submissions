class Solution:
    def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
        n = len(bottomLeft)
        ans = 0
        for i in range(n):
            for j in range(i + 1, n):
                l1 = bottomLeft[i]
                r1 = topRight[i]

                l2 = bottomLeft[j]
                r2 = topRight[j]

            

                # Found overlap
                height = max(0, min(r1[1], r2[1]) - max(l1[1], l2[1]))
                width  = max(0, min(r1[0], r2[0]) - max(l1[0], l2[0]))
                side = min(height,width)
                area = side*side
                ans = max(ans,area)

        return ans









        