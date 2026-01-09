# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    maxDepth = float("-inf")

    def findLca(self, maxDepth, currDepth, root):
        if not root or currDepth == maxDepth:
            return root

        leftN = self.findLca(maxDepth,currDepth+1,root.left)
        rightN = self.findLca(maxDepth,currDepth+1,root.right)

        if leftN and rightN:
            return root

        if leftN:
            return leftN
        elif rightN:
            return rightN

        else:
            return None




    def find_depth(self, root, mpp, depth):
        if not root:
            return

        mpp[root.val] = depth
        self.maxDepth = max(self.maxDepth, depth)
        self.find_depth(root.right, mpp,depth + 1)
        self.find_depth(root.left, mpp,depth + 1)

    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        mpp = defaultdict()

        self.find_depth(root, mpp, 0)

        return self.findLca(self.maxDepth, 0, root)
