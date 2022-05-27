class Solution {
    public int numberOfSteps(int n) {
        int step = 0;
        while(n > 0)
        {
            if((n&1) != 0)
            {
                n = n-1;
            }else{
                n = n/2;
            }
            step++;
        }
        
        return step;
    }
    
}