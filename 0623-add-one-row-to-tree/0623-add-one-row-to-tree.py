# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if root is None:
            return None
        if depth == 1:
            temp = TreeNode(val, root, None)
            return temp
        elif depth == 2:
            left = TreeNode(val, root.left, None)
            right = TreeNode(val, None, root.right)
            root.left, root.right = left, right
            return root
        else:
            self.addOneRow(root.left, val, depth - 1)
            self.addOneRow(root.right, val, depth - 1)
            return root
