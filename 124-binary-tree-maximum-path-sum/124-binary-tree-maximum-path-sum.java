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
        int maxValue = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
     
        maxPathSumUtil(root);


        return maxValue;
    }

    public int maxPathSumUtil(TreeNode root)
    {
        if(root == null)
        {
            return 0;
        }

        int leftSum;
        int rightSum;
        
        int l = maxPathSumUtil(root.left);
        int r = maxPathSumUtil(root.right);
        
        if( l < 0)
        {
            leftSum = 0;
        }else{
            leftSum = l;
        }
        
        if( r < 0)
        {
            rightSum = 0;
        }else{
            rightSum = r;
        }
        
        // calculate the /-\ umbrella sum and update the result
        maxValue = Math.max(maxValue, leftSum + rightSum + root.val);
        
        // can take either take left branch or right branch sum including node value
        return Math.max(leftSum, rightSum) + root.val;
        
    }
}