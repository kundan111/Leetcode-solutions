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
        public TreeNode buildTree(int[] preorder, int[] inorder) {
        

        if(preorder.length == 0 || inorder.length == 0)
        {
            return null;
        }

        HashMap<Integer,Integer> inorderHashMap = new HashMap<>();
        
        int sz = inorder.length;

        for (int i = 0; i < sz; i++) {
            inorderHashMap.put(inorder[i], i);
        }
        
        return recur(preorder, inorder, 0, sz-1, 0, sz-1, inorderHashMap);
        
    }

    public TreeNode recur(int[] preorder, int[] inorder, 
                int preStart, int preEnd,
                int inStart, int inEnd,
    HashMap<Integer,Integer> inorderHashMap)
    {

        if(preStart > preEnd || inStart > inEnd)
        {
            return null;
        }

        TreeNode newRoot = new TreeNode(preorder[preStart]);
        int inRoot = inorderHashMap.get(preorder[preStart]);

        int len = inRoot - inStart;

        newRoot.left = recur(preorder, inorder, preStart+1, preStart+len, inStart, inRoot-1, inorderHashMap);
        newRoot.right = recur(preorder, inorder, preStart+len+1, preEnd, inRoot+1, inEnd, inorderHashMap);


        return newRoot;

    }
}