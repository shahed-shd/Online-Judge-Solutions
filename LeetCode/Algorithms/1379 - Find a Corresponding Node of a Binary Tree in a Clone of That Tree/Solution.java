// ==================================================
// Problem  :   1379 - Find a Corresponding Node of a Binary Tree in a Clone of That Tree
// Run time :   0.001 sec
// Language :   Java
// ==================================================

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

public class Solution {
    static TreeNode dfs(TreeNode originalNode, TreeNode clonedNode, TreeNode targetNode) {
        if (originalNode == targetNode) {
            return clonedNode;
        }
        
        if (originalNode.left != null) {
            TreeNode refNode = dfs(originalNode.left, clonedNode.left, targetNode);
            if (refNode != null) {
                return refNode;
            }
        }
        
        if (originalNode.right != null) {
            TreeNode refNode = dfs(originalNode.right, clonedNode.right, targetNode);
            if (refNode != null) {
                return refNode;
            }
        }
        
        return null;
    }
    
    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        return dfs(original, cloned, target);
    }
}
