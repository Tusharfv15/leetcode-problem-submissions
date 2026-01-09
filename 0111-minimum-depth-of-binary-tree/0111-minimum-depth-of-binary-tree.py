# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    mindepth = 10**5 + 1

    def solve(self, root, currDepth):
        if not root:
            return 10**5 + 1
        if not root.left and not root.right:
            self.minDepth = min(currDepth, self.mindepth)
            return self.minDepth

        leftDepth = self.solve(root.left, currDepth + 1)
        rightDepth = self.solve(root.right, currDepth + 1)

        return min(leftDepth, rightDepth)

    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        return self.solve(root, 1)
