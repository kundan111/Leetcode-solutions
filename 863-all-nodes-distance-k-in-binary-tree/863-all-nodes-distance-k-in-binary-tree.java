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
    public List<Integer> distanceK(TreeNode root, TreeNode targetNode, int k) {
        
        // TreeNode targetNode = searchForNode(root, target);
        HashMap<TreeNode,TreeNode> mapper = new HashMap<>();
        parentMapper(root, mapper);

        HashMap<TreeNode,Integer> visited = new HashMap<>();
        ArrayList<Integer> res = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        KDistanceNodesUtil(targetNode, 0,q, mapper, visited,k);
        while (!q.isEmpty()) {
            TreeNode poll = q.poll();
            if(poll != null)
            {
                
                res.add(poll.val);
            }
        }

        
        return res;
    }
    void KDistanceNodesUtil(TreeNode root, int curSpiralDist, Queue<TreeNode> q, HashMap<TreeNode,TreeNode> mapper, HashMap<TreeNode,Integer> visited,
     int k)
    {
        
        q.add(root);

        while(curSpiralDist < k)
        {
            int sz = q.size();
            while(sz-- > 0)
            {
                TreeNode curNode = q.poll();
                visited.put(curNode, 1);

                if(!visited.containsKey(mapper.get(curNode)))
                {
                    // not present in visited HashMap so add in queue
                    q.add(mapper.get(curNode));
                }

                if(curNode != null && curNode.left != null && !visited.containsKey(curNode.left))
                {
                    q.add(curNode.left);
                }

                if(curNode != null && curNode.right != null && !visited.containsKey(curNode.right))
                {
                    q.add(curNode.right);
                }
                
            }

            curSpiralDist++;
            
        }
    }


    public void parentMapper(TreeNode root, HashMap<TreeNode,TreeNode> mapper)
    {
        
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            
            int sz = q.size();
            while(sz-- > 0)
            {
                TreeNode curNode = q.poll();
                if(curNode.left != null)
                {
                    mapper.put(curNode.left, curNode);
                    q.add(curNode.left);
                }

                if(curNode.right != null)
                {
                    mapper.put(curNode.right, curNode);
                    q.add(curNode.right);
                }
            }
        }

    }
    
}