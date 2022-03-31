// { Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            inputLine = br.readLine().trim().split(" ");
            int n = Integer.parseInt(inputLine[0]);
            int[] arr = new int[n];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }
            new Solution().segregate0and1(arr, n);
            for (int i = 0; i < n; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution {
    void segregate0and1(int[] arr, int n) {
                int sz = arr.length;
        int i = 0;
        int j = sz-1;
        
        while ( i < j) {
            while (i < sz && i < j && arr[i] == 0) {
                i++;
            }
            // i pointing to 1

            while (j >= 0 && i < j && arr[j] == 1) {
                j--;
            }

            // j pointing to 0

            // swap 

            if(i == sz || j == 0)
            {
                continue;
            }


            // System.out.println("i: " + i + "j: " + j);
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
            j--;
    }

}
}
