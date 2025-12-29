from collections import defaultdict
from typing import List

class Solution:
    def dfs(self, current, above, allowed, n, m, idx, mpp):
        if len(current) == 1:
            return True

        if idx == len(current) - 1:
            return self.dfs(above, [], allowed, n - 1, m, 0, mpp)

        prefix = current[idx] + current[idx + 1]
        if prefix not in mpp:
            return False

        for ch in mpp[prefix]:
            above.append(ch)
            if self.dfs(current, above, allowed, n, m, idx + 1, mpp):
                return True
            above.pop()

        return False

    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        mpp = defaultdict(list)

        for pattern in allowed:
            mpp[pattern[:2]].append(pattern[2])

        bottom_list = list(bottom)
        return self.dfs(bottom_list, [], allowed, len(bottom), len(allowed), 0, mpp)
