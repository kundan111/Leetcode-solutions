class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sz = nums.size();
        int repeating;
        int xor_res = 0;
        int c = 1;
        for(int i = 0; i < sz-1; i++)
        {
            xor_res = xor_res ^ (nums[i] ^ c);
            
            if(nums[i] == nums[i+1])
            {
                repeating = nums[i];
                
            }
            c++;
        }
        
        xor_res = xor_res ^ nums[sz-1] ^ sz;
        
        
        return vector<int>{repeating,xor_res^repeating};
        
        
    }
    
};