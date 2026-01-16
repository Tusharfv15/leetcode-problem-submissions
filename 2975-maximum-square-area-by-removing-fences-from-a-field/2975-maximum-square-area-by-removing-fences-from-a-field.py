class Solution:
    def maximizeSquareArea(self, m: int, n: int, hFences: List[int], vFences: List[int]) -> int:
        mod = 10**9 + 7
        hFences.append(1)
        hFences.append(m)
        vFences.append(1)
        vFences.append(n)
        h_gap = defaultdict(int)
        for i in range(len(hFences)):
            for j in range(i+1,len(hFences)):
                gap = abs(hFences[i]-hFences[j])
                h_gap[gap] = 1

        maxLen = -1 
        for i in range(len(vFences)):
            for j in range(i+1,len(vFences)):
                gap = abs(vFences[i]-vFences[j])
                if h_gap[gap] == 1:
                    maxLen = max(maxLen,gap)
        if maxLen == -1:
            return -1
        return (maxLen%mod)*(maxLen%mod)%mod


        