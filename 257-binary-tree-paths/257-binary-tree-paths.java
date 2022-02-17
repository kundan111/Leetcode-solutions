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
    List<String> v = new ArrayList();
    public List<String> binaryTreePaths(TreeNode root) {
        
        // StringBuilder s = new StringBuilder();
        String s ="";
        
        treePath(root,s);
        
        return v;
    }
    void treePath(TreeNode root, String s)
    {
        if(root.left ==null && root.right == null)
        {
            s = s.concat(Integer.toString(root.val));
            v.add(s.toString());
            return;
        }
        
        
        s = s.concat(Integer.toString(root.val));
        s = s.concat("->");
        if(root.left != null)
        {
            treePath(root.left,s);
        }
        if(root.right != null)
        {
            treePath(root.right,s);
        }
        
        
    }
}