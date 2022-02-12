/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isValidBST(TreeNode root) {
        
        return isValidBSTUtil(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    public boolean isValidBSTUtil(TreeNode root, long lower_bound, long upper_bound)
    {
        if(root == null)
        {
            return true;
        }
        return (root.val < upper_bound && root.val > lower_bound) && isValidBSTUtil(root.left, lower_bound, root.val) &&
        isValidBSTUtil(root.right, root.val, upper_bound);
    }
}