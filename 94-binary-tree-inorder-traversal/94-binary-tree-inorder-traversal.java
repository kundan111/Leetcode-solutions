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
    private List<Integer> res = new ArrayList(); 
    public List<Integer> inorderTraversal(TreeNode root) {
        util(root);
        return res;
    }
    private  void util(TreeNode root)
    {
        if(root != null)
        {
            util(root.left);
            res.add(root.val);
            util(root.right);
        }
    }
}