class Solution:
    
    def construct_bst(self, store_vals, l, r):
        if l > r:
            return None
        
        mid = (l + r) // 2
        
        root = TreeNode(store_vals[mid])
        root.left = self.construct_bst(store_vals, l, mid - 1)
        root.right = self.construct_bst(store_vals, mid + 1, r)
        
        return root

    def traverse(self, store_vals, root):
        if not root:
            return
        
        self.traverse(store_vals, root.left)
        store_vals.append(root.val)
        self.traverse(store_vals, root.right)

    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        store_vals = []
        
        self.traverse(store_vals, root)
        
        return self.construct_bst(store_vals, 0, len(store_vals) - 1)
