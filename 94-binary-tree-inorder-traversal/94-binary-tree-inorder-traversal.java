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
        TreeNode cur = root;
        while (cur != null) {
            st.push(cur);
            cur = cur.left;
        }

        while (st.size() > 0) {
            TreeNode pop = st.pop();
            res.add(pop.val);
            
            TreeNode fromHereGoright = pop.right;

            while (fromHereGoright != null) {
                st.push(fromHereGoright);
                fromHereGoright = fromHereGoright.left;
            }
        }


        return res;
        
    }
}