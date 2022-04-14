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
    public TreeNode searchBST(TreeNode root, int val) {
        return approach1(root, val);   
    }
    
    public TreeNode approach1(TreeNode root, int val) {
        
        if(root == null)
        {
            return root;
        }

        if(root.val == val)
        {
            return root;
        }

        TreeNode left = approach1(root.left, val);

        if(left != null)
        {
            return left;
        }

        TreeNode right = approach1(root.right, val);

        if(right != null)
        {
            return right;
        }

        return null;
    }
}