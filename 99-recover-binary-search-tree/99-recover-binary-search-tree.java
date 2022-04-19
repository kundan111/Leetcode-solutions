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
    List<TreeNode> oldAl = new ArrayList<>();
    public void recoverTree(TreeNode root) {
        
        inorder(root);

        List<TreeNode> newAl = new ArrayList<>(oldAl);

        Collections.sort(oldAl, new Comparator<TreeNode>() {

            @Override
            public int compare(TreeNode o1, TreeNode o2) {
                    // return (int)(o1.val - o2.val);
                    long a = o1.val*1L;
                    long b = o2.val*1L;
                
                    long res = (a - b);
                
                    return res < 0 ? -1 : 1 ;
                
            }
            
        });
        
        
        int sz = oldAl.size();

        int i = 0;
        for (i = 0; i < sz; i++) {
            if(oldAl.get(i).val != newAl.get(i).val) 
            {
                break;
            }
        }


        TreeNode firstNode = oldAl.get(i);
        TreeNode secondNode = newAl.get(i);

        int temp = firstNode.val;
        firstNode.val = secondNode.val;
        secondNode.val = temp;





    }

    void inorder(TreeNode root)
    {
        if(root == null)
        {
            return;
        }

        inorder(root.left);
        oldAl.add(root);
        inorder(root.right);
    }
}