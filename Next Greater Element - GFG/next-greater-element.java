// { Driver Code Starts
/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim());
		while(t-->0){
		    int n = Integer.parseInt(br.readLine().trim());
		    String inputLine[] = br.readLine().trim().split(" ");
		    long[] arr = new long[n];
		    for(int i=0; i<n; i++)arr[i]=Long.parseLong(inputLine[i]);
		    long[] res = new Solution().nextLargerElement(arr, n);
		    for (int i = 0; i < n; i++) 
		        System.out.print(res[i] + " ");
		    System.out.println();
		}
	}
}



// } Driver Code Ends


class Solution
{
    //Function to find the next greater element for each element of the array.
    public static long[] nextLargerElement(long[] arr, int n)
    {

        long[] ans = new long[arr.length];
        int sz = arr.length;
        Stack<Long> st = new Stack<>();

        for (int i = sz-1; i >= 0; i--) {
            
            long curEle = arr[i];

            while (!st.empty() && st.peek() <= curEle) {
                st.pop();
            }

            if(st.empty())
            {
                ans[i] = -1;
            }else{
                ans[i] = st.peek();
            }
            st.push(arr[i]);

        }
        
        return ans; 
    }
}