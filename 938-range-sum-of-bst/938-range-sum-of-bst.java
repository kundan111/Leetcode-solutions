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
    int res = 0;
    public int rangeSumBST(TreeNode root, int low, int high) {
        getCountUtil(root,low,high);
        return res;
    }
    void getCountUtil(TreeNode root,int l, int h)
    {
        if(root == null)
        {
            
            return;
        }

        // for Boundry l inclusive
        if(root.val == l)
        {
            res+=root.val;
            getCountUtil(root.right,l,h);
            return;
        }
        // for Boundry r inclusive
        if(root.val == h)
        {
            res+=root.val;
            getCountUtil(root.left,l,h);
            return;
        }

        // for between boundry
        if(l < root.val && root.val < h)
        {
            res+=root.val;
            getCountUtil(root.left, l, h);
            getCountUtil(root.right, l, h);
            return;
        }

        if(root.val < l)
        {
            getCountUtil(root.right,l,h);
            return;
        }

        if(root.val > h)
        {
            getCountUtil(root.left,l,h);
            return;
        }
    }
}