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
        public List<List<Integer>> levelOrder(TreeNode root) {
        
        List<List<Integer>> res = new ArrayList<>();
        
        if(root == null)
        {
            return res;
        }
            
        
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

            
        while (!q.isEmpty()) {
            
            int sz = q.size();

            res.add(new ArrayList<Integer>());
            while (sz-- > 0) {
                
                TreeNode curNode = q.poll();
                res.get(res.size()-1).add(curNode.val);

                if(curNode.left != null)
                {
                    q.add(curNode.left);
                }

                if(curNode.right != null)
                {
                    q.add(curNode.right);
                }
            }

        }
        
        
        return res;
    }
}