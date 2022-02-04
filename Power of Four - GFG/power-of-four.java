// { Driver Code Starts
import java.util.*;
class Check_Power_Of_4
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0)
		{
			long n = sc.nextLong();
			Solution ob = new Solution();
			System.out.println(ob.isPowerOfFour(n));
		t--;
		}
	}
}// } Driver Code Ends


class Solution
{
    static int val = 0;
    int isPowerOfFour(long n)
    {
	    isPowerof2(n);
	    int res = -1;
	    if(val%2 == 0)
	    {
	        res = 1;
	    }else{
	        res = 0;
	    }
	    
	    val = 0;
	    return res;
    }
     static void isPowerof2(long n)
    {
        if(n <= 0)
        {
            val = -1;
            return;
        }
        if(n == 1)
        {
            
            return;
        }
        if(n%2 == 1)
        {
            val = -1;
            return;
        }
        val++;
        isPowerof2(n/2);
    }
}