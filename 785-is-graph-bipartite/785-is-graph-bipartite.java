class Solution {
    int num_of_nodes;
    int[] colorArr;

    public boolean isBipartite(int[][] graph) {
        
        num_of_nodes = graph.length;
        colorArr = new int[num_of_nodes];

        for (int i = 0; i < num_of_nodes; i++) {
            colorArr[i] = -1;
        }


        // return checkBipartite(graph, 0, 1);


        for (int i = 0; i < graph.length; i++) {
            
            if(colorArr[i] == -1)
            {
                if(!checkBipartite(graph, i, 1))
                {
                    return false;
                }
            }
        }

        return true;
    }
    

    boolean checkBipartite(int[][] graph, int node, int color)
    {
        // System.out.println("checkBipartite(graph," + node + "," + color + ")");
        if(colorArr[node] != -1)
        {
            // already colored
            if(colorArr[node] != color)
            {
                return false;
            }
            return true;
        }

        colorArr[node] = color;
        boolean ans = true;
        
        for (int is : graph[node]) {
            ans = ans && checkBipartite(graph, is, 1-color);
        }

        return ans;

    }
}