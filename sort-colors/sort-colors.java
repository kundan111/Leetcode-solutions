class Solution {
    public void sortColors(int[] nums) {
        
        int sz = nums.length;
        
        if(sz == 0)
        {
            return;
        }
        
        /*
                  
        int zeroPointer = 0;
        int onePointer = 0;
        int twoPointer = sz-1;
        
        while(zeroPointer < onePointer)
        {
                    
        }
        */
        
        int zero = 0, one = 0, two = 0;
        for (int val : nums)
        {
            if(val == 0)
            {
                zero++;
            }else if(val == 1)
            {
                one++;
            }else{
                two++;
            }
        }
        
        // System.out.println(zero);
        // System.out.println(one);
        
        // System.out.println(two);
        
        int i = 0;
        
        while(i < zero)
        {
            nums[i] = 0;
            i++;
            
        }
        
        while(i < one+zero)
        {
            nums[i] = 1;
            i++;
        }
        
        while(i < one+zero+two)
        {
            nums[i] = 2;
            i++;
        }
        
        
        
    }
}