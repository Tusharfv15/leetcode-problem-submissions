# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def max_height(self,root):
        if not root:
            return 0


        left_height = 1 + self.max_height(root.left)
        right_height = 1 + self.max_height(root.right)

        return max(left_height,right_height)
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        left_ans = self.isBalanced(root.left)
        right_ans = self.isBalanced(root.right)

        diff = abs(self.max_height(root.left) - self.max_height(root.right)) <=1

        if left_ans and right_ans and diff:
            return True

        return  False

        
        