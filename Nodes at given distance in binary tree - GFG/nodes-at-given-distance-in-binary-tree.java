// { Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class Node  
{ 
    int data; 
    Node left, right; 
   
    public Node(int d)  
    { 
        data = d; 
        left = right = null; 
    } 
}

class GFG
{
    static Node buildTree(String str)
    {
        // Corner Case
        if(str.length() == 0 || str.equals('N'))
            return null;
        String[] s = str.split(" ");
        
        Node root = new Node(Integer.parseInt(s[0]));
        Queue <Node> q = new LinkedList<Node>();
        q.add(root);
        
        // Starting from the second element
        int i = 1;
        while(!q.isEmpty() && i < s.length)
        {
              // Get and remove the front of the queue
              Node currNode = q.remove();
        
              // Get the current node's value from the string
              String currVal = s[i];
        
              // If the left child is not null
              if(!currVal.equals("N")) 
              {
        
                  // Create the left child for the current node
                  currNode.left = new Node(Integer.parseInt(currVal));
        
                  // Push it to the queue
                  q.add(currNode.left);
              }
        
              // For the right child
              i++;
              if(i >= s.length)
                  break;
              currVal = s[i];
        
              // If the right child is not null
              if(!currVal.equals("N")) 
              {
        
                  // Create the right child for the current node
                  currNode.right = new Node(Integer.parseInt(currVal));
        
                  // Push it to the queue
                  q.add(currNode.right);
              }
              
              i++;
        }
    
        return root;
    }
    
    public static void main(String args[]) throws IOException
    {
    
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while(t>0)
        {
            String s = br.readLine().trim();
            Node root = buildTree(s);
            Solution T = new Solution();
            int target = Integer.parseInt(br.readLine().trim());
            int k = Integer.parseInt(br.readLine().trim());
            ArrayList<Integer> res = new ArrayList<Integer>();
            res = T.KDistanceNodes(root,target,k);
            for(int i = 0;i<res.size();i++)
                System.out.print(res.get(i) + " ");
            System.out.println();    
            t--;
        }
    }
}
// } Driver Code Ends


//User function Template for Java

// class Node  
// { 
//     int data; 
//     Node left, right;
// }

class Solution
{
    public static ArrayList<Integer> KDistanceNodes(Node root, int target , int k)
    {

        Node targetNode = searchForNode(root, target);
        HashMap<Node,Node> mapper = new HashMap<>();
        parentMapper(root, mapper);

        // GFGTree.printLine();
        // for (Entry<Node,Node> e: mapper.entrySet()) {
        //     System.out.println(e.getKey().data + " -> " + e.getValue().data);
        // }
        // GFGTree.printLine();

        HashMap<Node,Integer> visited = new HashMap<>();
        ArrayList<Integer> res = new ArrayList<>();
        Queue<Node> q = new LinkedList<>();
        KDistanceNodesUtil(targetNode, 0,q, mapper, visited,k);
        while (!q.isEmpty()) {
            Node poll = q.poll();
            if(poll != null)
            {
                
                res.add(poll.data);
            }
        }

        Collections.sort(res);

        return res;

    }   

    static void KDistanceNodesUtil(Node root, int curSpiralDist, Queue<Node> q, HashMap<Node,Node> mapper, HashMap<Node,Integer> visited,
     int k)
    {
        
        q.add(root);

        while(curSpiralDist < k)
        {
            int sz = q.size();
            while(sz-- > 0)
            {
                Node curNode = q.poll();
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


    static public void parentMapper(Node root, HashMap<Node,Node> mapper)
    {
        
        Queue<Node> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            
            int sz = q.size();
            while(sz-- > 0)
            {
                Node curNode = q.poll();
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

    static Node searchForNode(Node root, int target)
    {
        if(root == null)
        {
            return null;
        }

        if(root.data == target)
        {
            return root;
        }

        Node searchForNodeInLeft = searchForNode(root.left, target);
        if(searchForNodeInLeft != null)
        {
            return searchForNodeInLeft;
        }
        Node searchForNodeInRight = searchForNode(root.right, target);
        if(searchForNodeInRight != null)
        {
            return searchForNodeInRight;
        }

        return null;

    }
};