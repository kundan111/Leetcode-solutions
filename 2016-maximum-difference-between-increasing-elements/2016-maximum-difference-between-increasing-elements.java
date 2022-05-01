class Solution {
    public int maximumDifference(int[] arr) {
        
        
         int sz = arr.length;
        int res = Integer.MIN_VALUE;
        int minTillThisPoint = Integer.MAX_VALUE;
        // int minIndex = 0;
        
        int i = 0;
        
        
        while(i < sz)
        {
            
            if(arr[i] > minTillThisPoint)
            {
                res = Math.max((arr[i] - minTillThisPoint),res);    
            }
            
            if(arr[i] < minTillThisPoint)
            {
                minTillThisPoint = arr[i];
            }
            
            i++;;
            // System.out.println("res: " + res);
            
        }
        
        return res == Integer.MIN_VALUE ? -1 : res;
    }
}