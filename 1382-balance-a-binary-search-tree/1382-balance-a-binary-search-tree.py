# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def construct_bst(self,store_vals,l,r):
        if r < l:
            return None

        mid = (r + l)//2
        root = TreeNode(store_vals[mid])
        root.left = self.construct_bst(store_vals,l,mid-1)
        root.right = self.construct_bst(store_vals,mid+1,r)
        return root

    def traverse(self,store_vals,root):
        if not root:
            return

        self.traverse(store_vals,root.left)
        store_vals.append(root.val)
        self.traverse(store_vals,root.right)

        return
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        store_vals = []

        self.traverse(store_vals,root)
        n = len(store_vals)
        return self.construct_bst(store_vals,0,n-1)







        