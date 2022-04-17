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
    List<Integer> allNodes = new ArrayList<>();

    public TreeNode increasingBST(TreeNode root) {

        inorder(root);
        
        return rearrange(allNodes, 0);
    }
    void inorder(TreeNode root)
    {
        if(root == null)
        {
            return;
        }

        inorder(root.left);
        allNodes.add(root.val);
        inorder(root.right);
    }
    

    TreeNode rearrange(List<Integer> allNodes, int curIndex)
    {
        if(curIndex >= allNodes.size())
        {
            return null;
        }

        TreeNode root = new TreeNode(allNodes.get(curIndex));
        root.left = null;
        root.right = rearrange(allNodes, curIndex+1);


        return root;

    }
}