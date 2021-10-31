class Solution {
public:
    int smallestEqual(vector<int>& nums) {
     
        int k = 0;
        for(int &val : nums)
        {
            if(k%10 == val)
            {
                return k;
            }
        k++;
        }
        
        
    return -1;
    }
    
    
};