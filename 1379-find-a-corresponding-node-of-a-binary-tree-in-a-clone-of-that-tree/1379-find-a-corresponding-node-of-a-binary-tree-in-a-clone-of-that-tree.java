/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        
        TreeNode originalRootCopy = original;
        TreeNode cloneRootCopy = cloned;

        return traverse(originalRootCopy, cloneRootCopy, target);
    }

    TreeNode traverse(TreeNode original, TreeNode clone, TreeNode target)
    {
        
        if(original == null)
        {
            return null;
        }

        if(original == target)
        {
            return clone;
        }

        TreeNode l = traverse(original.left, clone.left, target);
        if(l != null)
        {
            return l;
        }

        TreeNode r = traverse(original.right, clone.right, target);
        if(r != null)
        {
            return r;
        }

        
        
        return null;
    }
}