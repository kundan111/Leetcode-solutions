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
    public int maxPathSum(TreeNode root) {
     
        int[] maxValue = new int[1];
        maxValue[0] = Integer.MIN_VALUE;

        maxPathSumUtil(root, maxValue);


        return maxValue[0];
    }

    public int maxPathSumUtil(TreeNode root, int[] maxValue)
    {
        if(root == null)
        {
            return 0;
        }

        int leftHeight;
        int rightHeight;
        
        int l = maxPathSumUtil(root.left,maxValue);
        int r = maxPathSumUtil(root.right,maxValue);
        if( l < 0)
        {
            leftHeight = 0;
        }else{
         leftHeight = l;
        }
        
        if( r < 0)
        {
            rightHeight = 0;
        }else{
         rightHeight = r;
        }
        
        
        maxValue[0] = Math.max(maxValue[0], leftHeight+rightHeight+root.val);
        
        return Math.max(leftHeight, rightHeight) + root.val;
        
    }
}