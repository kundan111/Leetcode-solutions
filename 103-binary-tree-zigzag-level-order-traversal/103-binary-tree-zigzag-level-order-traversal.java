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
    List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        levelOrderAlternate(root);
        return res;
    }
    
    void levelOrderAlternate(TreeNode root)
    {
        if(root == null)
           {
               return;
           }
           
       Queue<TreeNode> q = new LinkedList<>();
       q.add(root);
        
       boolean isEven = true;
       
       while(q.size() > 0)
       {
           int sz = q.size();
           ArrayList<Integer> al = new ArrayList<>();
           while(sz-- > 0)
           {
               TreeNode cur = q.poll();
               al.add(cur.val);

               if(cur.left != null)
               {
                   q.add(cur.left);
               }
               if(cur.right != null)
               {
                   q.add(cur.right);
               }
           }
           if(isEven)
           {
                res.add(al);
           }else{
               Collections.reverse(al);
                res.add(al);
           }
       
       isEven = !isEven;
       }
}
}