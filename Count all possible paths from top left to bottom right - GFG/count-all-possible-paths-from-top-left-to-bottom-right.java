// { Driver Code Starts
//Initial Template for Java
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String[] input = new String[2]; 
            input = br.readLine().split(" "); 
            int m = Integer.parseInt(input[0]); 
            int n = Integer.parseInt(input[1]); 
            Solution ob = new Solution();
            System.out.println(ob.numberOfPaths(m,n));
        }
    }
}
// } Driver Code Ends


//User function Template for Java
class Solution
{
    int res = 0;
    int row;
    int col;
    int MOD = 1000000007;
    long numberOfPaths(int m, int n)
    {
        row = m;
        col = n;

        long[][] cache = new long[row][col];

        for (long[] arr : cache) {
            Arrays.fill(arr, -1);
        }

        long result = numberOfPathsUtil(0, 0, m, n, cache);

        return result%MOD;
    }

    long numberOfPathsUtil(int i, int j, int m, int n, long[][] cache)
    {
        


        // reached at the bottom of the grid
        if(i == m-1 && j == n-1)
        {
            return 1l;
        }

        if(!isValid(i, j))
        {
            // point outside the grid 
            return 0l;
        }

        if(cache[i][j] != -1)
        {
            return cache[i][j];
        }

        return cache[i][j] =  (long)(numberOfPathsUtil(i, j+1, m, n,cache)%MOD + numberOfPathsUtil(i+1, j, m, n,cache)%MOD)%MOD;



    }

    boolean isValid(int i, int j)
    {
        return ((i >= 0 && i < row) && (j >=0 && j < col));
    }
}