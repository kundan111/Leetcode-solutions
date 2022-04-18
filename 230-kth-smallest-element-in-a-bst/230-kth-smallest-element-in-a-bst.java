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
    int counter = 0;
    int res = -1;
    public int kthSmallest(TreeNode root, int k) {
        
     
        approach1(root, k);
     
     
        return res;
    }

    public void approach1(TreeNode root, int k) {

        if(root == null)
        {
            return;
        }
        approach1(root.left, k);
        counter++;
        if(counter == k && res == -1)
        {
            res = root.val;
            return;
        }
        approach1(root.right, k);

    }
    
}