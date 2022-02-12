/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    public String serialize(TreeNode root) {
        StringBuilder res = new StringBuilder();
        
        levelOrderTraversal(root, res);
        
        // System.out.println(res);
        return res.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        
        if(data.length() == 0)
        {
            return null;
        }

        String[] splitArray = data.split(",");
    
        return deserializeUtil(splitArray);

    }

    TreeNode deserializeUtil(String[] splitArray)
    {
        Queue<TreeNode> q = new LinkedList<>();

        int sz = splitArray.length;
        TreeNode newRoot = new TreeNode(Integer.parseInt(splitArray[0]));
        q.add(newRoot);


        
        for (int i = 1; i < sz; i++) {
            TreeNode parent = q.poll();
            if(!splitArray[i].equals("#"))
            {
                TreeNode leftTree = new TreeNode(Integer.parseInt(splitArray[i]));
                parent.left = leftTree;
                q.add(leftTree);
            }
            
            if(!splitArray[++i].equals("#"))
            {
                TreeNode rightTree = new TreeNode(Integer.parseInt(splitArray[i]));
                parent.right = rightTree;
                q.add(rightTree);
            }
        }

        return newRoot;

    }

    
    void levelOrderTraversal(TreeNode root, StringBuilder s)
    {
        if(root == null)
        {
            return;
        }
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        

        while (!q.isEmpty()) {
            int sz = q.size();

            while (sz-- > 0) {
                TreeNode curNode = q.poll();
                if(curNode == null)
                {
                    s.append("#,");
                }else{

                    s.append(Integer.toString(curNode.val) + ",");
                }

                if(curNode != null)
                {
                    q.add(curNode.left);
                    q.add(curNode.right);    
                }
                
            }
        }
    }
    
    
}

