class Solution {
public:
    int numberOfSteps(int n) {
        int step = 0;
        while(n)
        {
            if(n&1)
            {
                n = n-1;
            }else{
                n = n/2;
            }
            step++;
        }
        
        return step;
    }
};