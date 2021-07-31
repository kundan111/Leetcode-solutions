class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int sz = nums.size();
        vector<int> vec(sz);
        
        int i = 0;
        int j = sz-1;
        
        
        int p = sz-1;
        while(i <= j)
        {
            if(nums[i]*nums[i] < nums[j]*nums[j])
            {
                vec[p] = nums[j]*nums[j];
                j--;
            }else{
                
                vec[p] = nums[i]*nums[i];
                i++;
            }
            
            
            p--;
        }
        
        
        return vec;
    }
};