// { Driver Code Starts
// Initial Template for Java

import java.util.*;
class Rat {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[][] a = new int[n][n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) a[i][j] = sc.nextInt();

            Solution obj = new Solution();
            ArrayList<String> res = obj.findPath(a, n);
            Collections.sort(res);
            if (res.size() > 0) {
                for (int i = 0; i < res.size(); i++)
                    System.out.print(res.get(i) + " ");
                System.out.println();
            } else {
                System.out.println(-1);
            }
        }
    }
}
// } Driver Code Ends


// User function Template for Java

// m is the given matrix and n is the order of matrix
class Solution {
    static int row;
    static int col;

    static ArrayList<String> res = new ArrayList<>();

    public static ArrayList<String> findPath(int[][] m, int n) {

        row = m.length;
        col = m[0].length;

        dfs(m, 0, 0, new StringBuilder());

        ArrayList<String> ans = new ArrayList<>(res);
        res.clear();
        return ans;
    }

    static void dfs(int[][] m, int i, int j, StringBuilder temp)
    {
        // rat reached destination
        if(i == row-1 && j == col-1)
        {
            if(m[i][j] == 1)
            {
                res.add(temp.toString());
            }
            return;
        }

        // already visited return 
        if(!isValid(i, j, m))
        {
            return;
        }

        m[i][j] = 2;
        
        // explore right
        temp.append("R");
        dfs(m, i, j+1, temp);
        temp.deleteCharAt(temp.length()-1);

        // explore down
        temp.append("D");
        dfs(m, i+1, j, temp);
        temp.deleteCharAt(temp.length()-1);

        //explore left
        temp.append("L");
        dfs(m, i, j-1, temp);
        temp.deleteCharAt(temp.length()-1);

        //explore up
        temp.append("U");
        dfs(m, i-1, j, temp);
        temp.deleteCharAt(temp.length()-1);

        m[i][j] = 1;


    }

    static boolean isValid(int i, int j, int[][] m)
    {
        return (((i >= 0 && i < row) && (j >=0 && j < col)) && (m[i][j] == 1));
    }
}