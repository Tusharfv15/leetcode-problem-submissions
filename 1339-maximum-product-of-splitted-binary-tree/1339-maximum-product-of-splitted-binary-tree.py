# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    mod = 10**9 + 7

    def find(self, root, total_tree_sum):
        if not root:
            return 0

        left_tree = self.find(root.left, total_tree_sum)
        right_tree = self.find(root.right, total_tree_sum)

        subtree_sum = root.val + left_tree + right_tree
        rem_sum = total_tree_sum - subtree_sum

        product = (subtree_sum) * (rem_sum)
        self.ans = max(self.ans, product)

        return subtree_sum

    def find_total_tree_sum(self, root):
        if not root:
            return 0

        left_sub_tree_sum = self.find_total_tree_sum(root.left)
        right_sub_tree_sum = self.find_total_tree_sum(root.right)

        return root.val + left_sub_tree_sum + right_sub_tree_sum

    def maxProduct(self, root: Optional[TreeNode]) -> int:
        self.ans = 0  

        total_tree_sum = self.find_total_tree_sum(root)
        self.find(root, total_tree_sum)

        return self.ans%self.mod
