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
    
    int maxLevelFound = -1; 
    int sumAtMaxLevel = 0;

    
    public int deepestLeavesSum(TreeNode root) {
        // int sumAtMaxLevel = 0;
        int curLevel = 0;
        return sumAtLevel(root, curLevel);
        
        
         
    }

    int sumAtLevel(TreeNode curNode,  int curLevel)
    {
        // System.out.println("sumAtLevel(" + (curNode == null ? "null" : curNode.val) +","+ curLevel + ")");
        if(curNode == null)
        {
            return 0;
        }

        if(curLevel > maxLevelFound)
        {
            maxLevelFound = curLevel;
            sumAtMaxLevel = curNode.val;
        }else if(curLevel == maxLevelFound)
        {
            sumAtMaxLevel += curNode.val;
        }

        sumAtLevel(curNode.left, curLevel+1);
        sumAtLevel(curNode.right, curLevel+1);


        return sumAtMaxLevel;
        
    }
}