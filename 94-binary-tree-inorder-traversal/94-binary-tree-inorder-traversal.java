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
        public List<Integer> inorderTraversal(TreeNode root) {
        
        List<Integer> res = new ArrayList<>();

        if(root == null)
        {
            return res;
        }

        Stack<TreeNode> st = new Stack<>();
        TreeNode curNode = root;
        while (true) {
            while (curNode != null) {
                st.push(curNode);
                curNode = curNode.left;
            }

            if(st.size() == 0)
            {
                break;
            }

            TreeNode topEle = st.pop();
            res.add(topEle.val);
            curNode = topEle.right;
            
        }
     
     
        return res;
        
    }
}