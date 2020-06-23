# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    
    def depth(self, root: TreeNode) -> int:
        d = 0
        while root.left:
            root = root.left
            d += 1
        return d
    
    def exists(self, idx, d, root) -> int:
        lo, hi = 0, 2**d - 1
        for _ in range(d):
            mid = lo + (hi-lo)//2
            if idx <= mid:
                root = root.left
                hi = mid
            else:
                root = root.right
                lo = mid+1
        return root is not None
                
    
    def countNodes(self, root: TreeNode) -> int:
        # return 1 + self.countNodes(root.left) + self.countNodes(root.right) if root else 0
        if not root:
            return 0
        d = self.depth(root)
        if d == 0:
            return 1
        
        lo, hi = 0, 2**d - 1
        while lo <= hi:
            mid = lo + (hi-lo)//2
            if self.exists(mid, d, root):
                lo = mid+1
            else:
                hi = mid-1
        
        return 2**d - 1 + lo
        
