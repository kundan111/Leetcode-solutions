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
    public List<Integer> rightSideView(TreeNode root) {
                
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        ArrayList<Integer> res = new ArrayList<>();

        if(root ==  null)
        {
            return res;
        }
        
        while (!q.isEmpty()) {
            
            int sz = q.size();

            int i = 0;
            while (i < sz) {
                
                TreeNode curNode = q.poll();
                if(i == sz-1)
                {
                    res.add(curNode.val);
                }

                if(curNode.left != null)
                {
                    q.add(curNode.left);
                }
                if(curNode.right !=  null)
                {
                    q.add(curNode.right);
                }
                i++;
            }
        }

        return res;
    }
}