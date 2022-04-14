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
        return approach2(root, val);
    }
    
    public TreeNode approach2(TreeNode root, int val) {
        
        if(root == null)
        {
            return root;
        }

        if(root.val == val)
        {
            return root;
        }

        if(root.val < val)
        {
            TreeNode right = approach2(root.right, val);
            if(right != null)
            {
                return right;
            }
        }

        if(root.val > val)
        {
            TreeNode left = approach2(root.left, val);
            if(left != null)
            {
                return left;
            }
        }

        return null;
    }
}