class Solution {
    public void merge(int[] num1, int m, int[] num2, int n) {
        
        for(int i = m; i < m+n; i++)
        {
            num1[i] = Integer.MAX_VALUE;
        }
        
        int[] temp = new int[m+n];
        
        int i = 0;
        int j = 0;
        int curIndex = 0;
        while(i < m || j < n)
        {
            int first, second;
            if(i < m)
            {
                first = num1[i];
            }else{
                first = Integer.MAX_VALUE;
            }
            
            if(j < n)
            {
                second = num2[j];
            }else{
                second = Integer.MAX_VALUE;
            }
            
            
            
            // System.out.println("first: " + first);
            // System.out.println("second: " + second);
            
            
            if(first <= second)
            {
                temp[curIndex] = first;
                i++;
            }else{
                
                temp[curIndex] = second;
                j++;
            }
            curIndex++;
        }
        
        for(int k = 0; k < m+n; k++)
        {
            num1[k] = temp[k];
        }
        
    }
}

