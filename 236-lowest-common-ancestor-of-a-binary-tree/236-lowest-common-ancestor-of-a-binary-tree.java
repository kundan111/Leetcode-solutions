/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        
        if(root == null)
        {
            return null;
        }

        if(root == p || root == q)
        {
            return root;
        }

        TreeNode rootFromLeft = lowestCommonAncestor(root.left, p, q);
        TreeNode rootFromRight = lowestCommonAncestor(root.right, p, q);


        if(rootFromLeft != null && rootFromRight != null)
        {
            return root;
        }
        

        return rootFromLeft != null ? rootFromLeft : rootFromRight;


    }
}