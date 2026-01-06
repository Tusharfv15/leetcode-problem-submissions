from collections import deque
from typing import Optional

class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        queue = deque()
        queue.append((root, 1))

        level = 1
        ans = 1
        max_level_sum = float('-inf')

        while queue:
            level_sum = 0

            while queue and queue[0][1] == level:
                node, height = queue.popleft()

                level_sum += node.val   

                if node.left:
                    queue.append((node.left, height + 1))
                if node.right:
                    queue.append((node.right, height + 1))

            if level_sum > max_level_sum:  
                max_level_sum = level_sum
                ans = level

            level += 1

        return ans
