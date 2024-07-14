# ==================================================
# Problem  :   226. Invert Binary Tree
# Run time :   0.064 sec
# Language :   Python3
# ==================================================


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def dfs(node: Optional[TreeNode]) -> Optional[TreeNode]:
    if node:
        dfs(node.left)
        dfs(node.right)

        tmp = node.left
        node.left = node.right
        node.right = tmp


class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        dfs(root)
        return root
