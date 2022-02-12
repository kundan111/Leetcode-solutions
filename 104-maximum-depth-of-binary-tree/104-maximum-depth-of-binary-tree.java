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
 public int maxDepth(TreeNode root)
    {

        return util(root,0);
    }

    public int util(TreeNode root, int level)
    {
        if(root == null)
        {
            return 0;
        }

        int left = util(root.left, level+1);
        int right = util(root.right, level+1);

        
        return Integer.max(left, right) + 1;
    }
}