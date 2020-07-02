# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if root == None:
            return None
        import collections
        de = collections.deque()
        chld = []
        chld.append(root)
        while len(chld) != 0:
            chld2 = []
            val = []
            for node in chld:
                val.append(node.val)
                if node.left != None:
                    chld2.append(node.left)
                if node.right != None:
                    chld2.append(node.right)
            de.appendleft(val)
            chld = chld2
        
        return list(de)
            
