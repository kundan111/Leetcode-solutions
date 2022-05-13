/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        
        if(root == null)
        {
            return root;
        }
        
        Queue<Node> q = new LinkedList<>();
        q.add(root);


        while (!q.isEmpty()) {
        
            int sz = q.size();
            boolean isFirst = true;
            Node prevNode = null;
            while (sz-- > 0) {
                Node curNode = q.poll();
                if(isFirst)
                {
                    curNode.next = null;
                    prevNode = curNode;
                    isFirst = false;
                }else{
                    prevNode.next = curNode;
                    prevNode = curNode;
                }

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

        
        

        return root;
    }
}