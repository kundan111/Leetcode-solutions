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
    public TreeNode sortedArrayToBST(int[] nums) {
        
        int sz = nums.length;
        return createBST(nums, 0, sz-1);

    }

    TreeNode createBST(int[] nums, int l, int r)
    {
        
        if(r < l)
        {
            return null;
        }
        

        int mid = l + (r-l)/2;
        TreeNode newNode = new TreeNode(nums[mid]);

        newNode.left = createBST(nums, l, mid-1);
        newNode.right = createBST(nums, mid+1, r);

        return newNode;
    }
}