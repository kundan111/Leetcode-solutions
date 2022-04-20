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
class BSTIterator {

    ArrayList<Integer> inorderAl = new ArrayList<>();
    int i = -1;
    int sz;
    public BSTIterator(TreeNode root) {
        inorder(root);
        sz = inorderAl.size();
    }
    
    public int next() {
        if(i+1 < sz)
        {
            i++;
            return inorderAl.get(i);
        }
        // we should not hit this case
        return -1;
    }
    
    public boolean hasNext() {
        
        return (i + 1) < sz;
    }

    void inorder(TreeNode root)
    {
        if(root == null)
        {
            return;
        }
        inorder(root.left);
        inorderAl.add(root.val);
        inorder(root.right);
    }

}


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */